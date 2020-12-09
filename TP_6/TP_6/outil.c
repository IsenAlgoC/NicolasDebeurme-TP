#include <stdio.h>   /* pour les entrées-sorties */
#include <string.h>  /* pour les manipulations de chaînes de caractères */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

#define VERSION 3.0
#define SQUELET
/**************************************************************************/
/* Compléter votre nom ici                                                */
/*   Nom :Debeurme                         Prénom :Nicolas                */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le répertoire stocké en mémoire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr)
{
	
#ifdef IMPL_TAB
	int idx;
	if (rep->nb_elts < MAX_ENREG) //On ajoute un contact à la fin du repertoire si le nombre max de contact est pas dépassé
	{
		*(rep->tab + rep->nb_elts) = enr;
		rep->nb_elts ++;
		trier(rep);
		rep->est_trie = true;
		modif = true;

	}
	else {
		return(ERROR);
	}

	
#else
#ifdef IMPL_LIST
	int i = 0;
	bool inserted = false;
	if (rep->nb_elts == 0) {//Si la liste est vide on creer le premier maillon
		if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
			rep->nb_elts += 1;
			rep->est_trie = true;
			inserted = true;
		}

	}
	else {
			if (rep->nb_elts < MAX_ENREG) {//On ajoute l'elemnt en le triant directement
				SingleLinkedListElem* elem = NULL;
				elem = rep->liste->head;
				while (!inserted && i <= rep->liste->size)//Permet de mettre lelement à l'endroit ou il doit être alphabetiquement
				{
					if (elem == NULL) {
						if (InsertElementAt(rep->liste, i, enr) != 0) {
							rep->nb_elts += 1;
							rep->est_trie = true;
							inserted = true;
						}
					}
					else {
						if (est_sup(enr, elem->pers)) {
							if (InsertElementAt(rep->liste, i, enr) != 0) {
								rep->nb_elts += 1;
								rep->est_trie = true;
								inserted = true;
							}
						}
						elem = elem->next;
					}
					
					i++;
				}

			}

	}

#endif
	
#endif

	modif = true; 
	if (inserted)  return OK;
	else return ERROR;

} /* fin ajout */
  /**********************************************************************/
  /* supprime du répertoire l'enregistrement dont l'indice est donné en */
  /*   paramètre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB
void supprimer_un_contact_dans_rep(Repertoire *rep, int indice) {

	if (rep->nb_elts >= 1)		/* s'il y a au moins un element ds le tableau */
	{						/* et que l'indice pointe a l'interieur */

		if (indice > -1 && indice < rep->nb_elts) {
			for (int i = indice; i < rep->nb_elts - 1; i++) {
				*(rep->tab + i) = *(rep->tab + i + 1);
			}
			rep->nb_elts -= 1;		/* ds ts les cas, il y a un element en moins */
			modif = true;
		}
		else modif = false;
	}

	return;
} /* fin supprimer */

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* supprime du répertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif à vrai                              */
  /************************************************************************/
  // complet

	int supprimer_un_contact_dans_rep_liste(Repertoire *rep, SingleLinkedListElem *elem) {
	
	int ret=DeleteLinkedListElem(rep->liste, elem);//Suppression du maillon contenant elem
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0); 
	}
#endif
#endif


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement sur une ligne à l'écran  */
  /* ex Dupont, Jean                 0320304050                         */
  /**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	printf_s("%s,%s", enr.nom, enr.prenom);
	printf_s("%30s", enr.tel);


} /* fin affichage_enreg */
  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /* pour les listes                                                    */
  /* ex | Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{	
	int space = 0;
	printf("| ");
	printf_s("%s", enr.nom);
	space = MAX_NOM - strlen(enr.nom);
	for (int i = 0; i < space; i++)
		printf_s(" ");
	printf("| ");
	printf_s("%s", enr.prenom);
	space= MAX_NOM - strlen(enr.prenom);
	for (int i = 0; i < space; i++)
		printf_s(" ");
	printf("| ");
	printf_s("%s", enr.tel);
	space = MAX_TEL - strlen(enr.tel);
	for (int i = 0; i < space; i++)
		printf_s(" ");
	
	printf("\n");
} /* fin affichage_enreg */


  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                                                           */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2)  //return true si enr1 est avant enr2, false sinon
{
	if (_strcmpi(enr1.nom, enr2.nom) < 0) return true;
	if (_strcmpi(enr1.nom, enr2.nom) == 0) {
		if (_strcmpi(enr1.prenom, enr2.prenom) < 0)return true;
		if (_strcmpi(enr1.prenom, enr2.prenom) == 0) {
			for (int i = 0; i < MAX_TEL; i++)
			{
				if (enr1.tel[i] < enr2.tel[i]) 
					return true;
			}
		}
	}
	return(false);
	

}
 
/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements                   */
/*********************************************************************/

void trier(Repertoire *rep)
{

#ifdef IMPL_TAB
	Enregistrement tabl;
	for (int i = 0; i < (rep->nb_elts -1); i++)
	{
		for ( int j = (rep->nb_elts -1); j >i; j--)
		{
			if (!est_sup(*(rep->tab + i), *(rep->tab + j))) {
				tabl = *(rep->tab + i);
				*(rep->tab + i) = *(rep->tab + j);
				*(rep->tab + j) = tabl;
			}

		}
	}
	


	
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien à faire !
	// la liste est toujours triée
#endif
#endif


	rep->est_trie = true;
	modif = true;

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le répertoire d'un enregistrement correspondant au  */
  /*   nom à partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au critère ou*/
  /*   un entier négatif si la recherche est négative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire *rep, char nom[], int ind)
{
	int i = ind;		    /* position (indice) de début de recherche dans tableau/liste rep */
	int ind_fin=rep->nb_elts;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];	/* on place la chaine recherchee et la chaine lue dans le */
							/* tableau, afin de les convertir en majuscules et les comparer */
	bool trouve = false;		


#ifdef IMPL_TAB
	strcpy_s(tmp_nom, MAX_NOM, nom);
	_strupr_s(tmp_nom,MAX_NOM);
	while(!trouve&&i<ind_fin){
		strcpy_s(tmp_nom2,MAX_NOM,  rep->tab[i].nom);
		_strupr_s(tmp_nom2,MAX_NOM);
		if(_strcmpi(tmp_nom,tmp_nom2)==0) trouve=true ;
		i++;
	}
#else
#ifdef IMPL_LIST
	strcpy_s(tmp_nom, MAX_NOM, nom);
	_strupr_s(tmp_nom, MAX_NOM);
	while (!trouve && i < ind_fin) {
		strcpy_s(tmp_nom2, MAX_NOM, GetElementAt(rep->liste,i)->pers.nom);
		_strupr_s(tmp_nom2, MAX_NOM);
		if (_strcmpi(tmp_nom, tmp_nom2) == 0) trouve = true;
		i++;
	}

#endif
#endif

	return((trouve) ? (i-1) : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non numériques de la chaines        */
  /*********************************************************************/
void compact(char *s)
{
	for (int i = 0; i < MAX_TEL; i++)
	{
		if (isdigit(*(s + i)) == 0) {
			for (int j = i; j < MAX_TEL-1; j++)
				*(s + j) = *(s + j + 1);
			*(s + MAX_TEL - 1) = 0;
		}
	}

	return;
}

/**********************************************************************/
/* sauvegarde le répertoire dans le fichier dont le nom est passé en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionné ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
#ifdef IMPL_TAB
	if(fopen_s(&fic_rep,nom_fichier, "w+")!=0 || fic_rep==NULL)
		return ERROR;
	else {
		int i = 0;
		while (i < rep->nb_elts) {
			fprintf(fic_rep, "%s;", rep->tab[i].nom);
			fprintf(fic_rep, "%s;", rep->tab[i].prenom);
			fprintf(fic_rep, "%s\n", rep->tab[i].tel);
			i++;
		}
		

	}
	fclose(fic_rep);
	return 0;
#else
#ifdef IMPL_LIST
	if (fopen_s(&fic_rep, nom_fichier, "w+") != 0 || fic_rep == NULL)
		return ERROR;
	else {
		int i = 0;
		while (i < rep->nb_elts) {
			fprintf(fic_rep, "%s;", GetElementAt(rep->liste, i)->pers.nom);
			fprintf(fic_rep, "%s;", GetElementAt(rep->liste, i)->pers.prenom);
			fprintf(fic_rep, "%s\n", GetElementAt(rep->liste, i)->pers.tel);
			i++;
		}


	}
	fclose(fic_rep);
	return 0;
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le répertoire le contenu du fichier dont le nom est  */
  /*   passé en argument                                                */
  /*   retourne OK si le chargement a fonctionné et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char *char_nw_line;
	
	_set_errno(0);
	if ( ((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0) || (fic_rep == NULL) )
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
				Enregistrement pers = { {'A'},{'A'},{'0'} };
				SingleLinkedListElem *elem = NULL;
				InsertElementAt(rep->liste,num_rec,pers);
				elem = GetElementAt(rep->liste, (num_rec));
				if (lire_champ_suivant(buffer, &idx, elem->pers.nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, elem->pers.prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, elem->pers.tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
#endif
#endif




			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */