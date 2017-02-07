#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "couleurs.h"

#include <string.h>

#define U1 1
#define U2 2
#define IA 0

/*
display possibles: Mettre en paramètre les sorties, cimetieres et le joueur (J1 ou J2)
*/


char pion(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		return ' ';
	else if (c>0)
		return 'O';
	else
		return 'X';
}

void pion_mil(int c)
{	
	if (abs(c) < 5)
		printf("  ");
	else if (abs(c) >= 10)
		printf("1%c",c%10+48);
	else if (abs(c) > 5 )
		printf("%c ",c+48);
	else if (c > 0)
		printf("O ");
	else
		printf("X ");
}


void display(int T[25], int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	printf(" ____________________________\n");
	printf("|%c'%c'%c'%c'%c'%c |%c  |%c'%c'%c'%c'%c'%c |\\ Sortie : %d \n", pion(T[13],1),pion(T[14],1), pion(T[15],1), pion(T[16],1), pion(T[17],1), pion(T[18],1), Cimetiere_IA, pion(T[19],1),pion(T[20],1), pion(T[21],1), pion(T[22],1), pion(T[23],1), pion(T[24],1), Sortie_U);
	printf("|%c %c %c %c %c %c |%c  |%c %c %c %c %c %c |\\  \n", pion(T[13],2),pion(T[14],2), pion(T[15],2), pion(T[16],2), pion(T[17],2), pion(T[18],2), Cimetiere_IA, pion(T[19],2),pion(T[20],2), pion(T[21],2), pion(T[22],2), pion(T[23],2), pion(T[24],2));	
	printf("|%c %c %c %c %c %c |%c  |%c %c %c %c %c %c |\\  \n", pion(T[13],3),pion(T[14],3), pion(T[15],3), pion(T[16],3), pion(T[17],3), pion(T[18],3), Cimetiere_IA, pion(T[19],3),pion(T[20],3), pion(T[21],3), pion(T[22],3), pion(T[23],3), pion(T[24],3));	
	printf("|%c %c %c %c %c %c |%c  |%c %c %c %c %c %c |\\  \n", pion(T[13],4),pion(T[14],4), pion(T[15],4), pion(T[16],4), pion(T[17],4), pion(T[18],4), Cimetiere_IA, pion(T[19],4),pion(T[20],4), pion(T[21],4), pion(T[22],4), pion(T[23],4), pion(T[24],4));	

	printf("|");
	for (k=13;k<18;k++) pion_mil(T[k]);
	pion_mil(T[k]);
	printf("|");
	pion_mil(Cimetiere_IA);
	printf("|");
	for (k=19;k<24;k++) pion_mil(T[k]);
	pion_mil(T[k]);
	printf("|\\\n");

	printf("|            |  |            |\\\n");

	printf("|");
	for (k=12;k>7;k--) pion_mil(T[k]);
	pion_mil(T[k]);
	printf("|");
	pion_mil(Cimetiere_U);
	printf("|");
	for (k=6;k>1;k--) pion_mil(T[k]);
	pion_mil(T[k]);
	printf("|\\\n");

	printf("|%c %c %c %c %c %c |%c  |%c %c %c %c %c %c |\\  \n", pion(T[12],4),pion(T[11],4), pion(T[10],4), pion(T[9],4), pion(T[8],4), pion(T[7],4), Cimetiere_U, pion(T[6],4),pion(T[5],4), pion(T[4],4), pion(T[3],4), pion(T[2],4), pion(T[1],4));	
	printf("|%c %c %c %c %c %c |%c  |%c %c %c %c %c %c |\\  \n", pion(T[12],3),pion(T[11],3), pion(T[10],3), pion(T[9],3), pion(T[8],3), pion(T[7],3), Cimetiere_U, pion(T[6],3),pion(T[5],3), pion(T[4],3), pion(T[3],3), pion(T[2],3), pion(T[1],3));	
	printf("|%c %c %c %c %c %c |%c  |%c %c %c %c %c %c |\\  \n", pion(T[12],2),pion(T[11],2), pion(T[10],2), pion(T[9],2), pion(T[8],2), pion(T[7],2), Cimetiere_U, pion(T[6],2),pion(T[5],2), pion(T[4],2), pion(T[3],2), pion(T[2],2), pion(T[1],2));	
	printf("|%c,%c,%c,%c,%c,%c |%c  |%c,%c,%c,%c,%c,%c |\\ Sortie : %d \n", pion(T[12],1),pion(T[11],1), pion(T[10],1), pion(T[9],1), pion(T[8],1), pion(T[7],1), Cimetiere_U, pion(T[6],1),pion(T[5],1), pion(T[4],1), pion(T[3],1), pion(T[2],1), pion(T[1],1), Sortie_IA);
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	printf(" 12  10   8         5   3   1\n");
	printf("   11  9    7     6   4   2\n");
}









void possibles_pion_haut_J1(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf(" '");
	else if (i == abs(c) && c<0) //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X'");
		//color(7,0);
		//Version portable
		//printf("A'");
		//Version Linux
		couleur("31");
		printf("X'");
		couleur("0");
	}
	else if (c>0)
		printf("O'");
	else
		printf("X'");
}

void possibles_pion_J1(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf("  ");
	else if (i == abs(c) && c<0) //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X ");
		//color(7,0);
		//Version portable
		//printf("A ");
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else if (c>0)
		printf("O ");
	else
		printf("X ");
}

void possibles_pion_mil_J1(int c)
{	
	if (abs(c) < 5)
		printf("  ");
	else if (c == -5)  //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X ");
		//color(7,0);
		//Version portable
		//printf("A ");
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else if (c == 5)
		printf("O ");
	else if (c <= 10) //pion possible J1 >= 10
	{
		//Version Windows
		//color(12,0);
		//printf("1%c",c%10+48);
		//color(7,0);
		//Version portable
		//printf("A%c",c%10+48);
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else if (c >= 10)
		printf("1%c",c%10+48);
	else if(c < -5 )   //pion possible J1 entre 5 et 10 
	{
		//Version Windows
		//color(12,0);
		//printf("%c ",c+48);
		//color(7,0);
		//Version portable
		//printf("%cA",c+48);
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else
		printf("%c ",c+48);
}

void possibles_pion_bas_J1(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf(" ,");
	else if (i == abs(c) && c<0) //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X,");
		//color(7,0);
		//Version portable
		//printf("A,");
		//Version Linux
		couleur("31");
		printf("X,");
		couleur("0");
	}
	else if (c>0)
		printf("O,");
	else
		printf("X,");
}

void possibles_pion_haut_J2(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf(" '");
	else if (i == abs(c) && c>0) //pion possible J2
	{
		//Version Windows
		//color(5,0);  
		//printf("O'");
		//color(7,0);
		//Version portable
		//printf("Q'");
		//Version Linux
		couleur("32");
		printf("O'");
		couleur("0");
	}
	else if (c>0)
		printf("O'");
	else
		printf("X'");
}

void possibles_pion_J2(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf("  ");
	else if (i == abs(c) && c>0) //pion possible J2
	{
		//Version Windows
		//color(5,0);
		//printf("O ");
		//color(7,0);
		//Version portable
		//printf("Q ");
		//Version Linux
		couleur("32");
		printf("O ");
		couleur("0");
	}
	else if (c>0)
		printf("O ");
	else
		printf("X ");
}

void possibles_pion_mil_J2(int c)
{	
	if (abs(c) < 5)
		printf("  ");
	else if (c == -5)
		printf("X ");
	else if (c == 5)   //pion possible J2
	{
		//Version Windows
		//color(5,0);
		//printf("O ");
		//color(7,0);
		//Version portable
		//printf("Q ");
		//Version Linux
		couleur("32");
		printf("O ");
		couleur("0");
	}
	else if (c <= 10)
		printf("1%c",c%10+48);
	else if (c >= 10)  //pion possible J2 >= 10
	{
		//Version Windows
		//color(5,0);
		//printf("1%c",c%10+48); 
		//color(7,0);
		//Version portable
		//printf("Q%c",c%10+48); 
		//Version Linux
		couleur("32");
		printf("O ");
		couleur("0");
	} 
	else if(c < -5 )
		printf("%c ",c+48);
	else    //pion possible J2 entre 5 et 10
	{
		//Version Windows
		//color(5,0);
		//printf("%c ",c+48);
		//color(7,0);
		//Version portable
		//printf("%cQ",c+48);	
		//Version Linux
		couleur("32");
		printf("O ");
		couleur("0");
	}		 
}

void possibles_pion_bas_J2(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf(" ,");
	else if (i == abs(c) && c>0) //pion possible J2
	{
		//Version Windows
		//color(5,0);
		//printf("O,");
		//color(7,0);
		//Version portable
		//printf("Q,");
		//Version Linux
		couleur("32");
		printf("O,");
		couleur("0");
	}
	else if (c>0)
		printf("O,");
	else
		printf("X,");
}






void display_pions_possibles_gen(int T[25], int joueur, int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	//Affichage première ligne du plateau
	printf(" ____________________________\n");
	
	if (joueur == 1)
	{
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_haut_J1(T[k],1);
		possibles_pion_J1(T[k],1);
		printf("|");
		possibles_pion_J1(Cimetiere_IA,i);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_haut_J1(T[k],1);
		possibles_pion_J1(T[k],1);
		printf("|\\	Sortie : %d\n", Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
				possibles_pion_J1(T[k],i);
			printf("|");
			possibles_pion_J1(Cimetiere_IA,i);
			printf("|");
			for (k=19;k<24;k++)
				possibles_pion_J1(T[k],i);
			possibles_pion_J1(T[k],i);
			printf("|\\\n");
		}

		//Affichage milieu du plateau----------------------------------------------
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_mil_J1(T[k]);
		possibles_pion_mil_J1(T[k]);
		printf("|");
		possibles_pion_mil_J1(Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_mil_J1(T[k]);
		possibles_pion_mil_J1(T[k]);
		printf("|\\\n");
	
		printf("|            |  |            |\\\n");
	
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_mil_J1(T[k]);
		possibles_pion_mil_J1(T[k]);
		printf("|");
		possibles_pion_mil_J1(Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_mil_J1(T[k]);
		possibles_pion_mil_J1(T[k]);
		printf("|\\\n");
		//Affichage fin du milieu de plateau----------------------------------------
	
		for (i=4;i>1;i--)
		{
			printf("|");
			for (k=12;k>6;k--)
				possibles_pion_J1(T[k],i);
			printf("|");
			possibles_pion_J1(Cimetiere_U,i);
			printf("|");
			for (k=6;k>1;k--)
				possibles_pion_J1(T[k],i);
			possibles_pion_J1(T[k],i);
			printf("|\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_bas_J1(T[k],i);
		possibles_pion_J1(T[k],i);
		printf("|");
		possibles_pion_J1(Cimetiere_U,i);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_bas_J1(T[k],i);
		possibles_pion_J1(T[k],i);
		printf("|\\ Sortie: %d\n", Sortie_IA);
	}




	else if (joueur == 2)
	{
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_haut_J2(T[k],1);
		possibles_pion_J2(T[k],1);
		printf("|");
		possibles_pion_J2(Cimetiere_IA,i);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_haut_J2(T[k],1);
		possibles_pion_J2(T[k],1);
		printf("|\\	Sortie : %d\n", Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
				possibles_pion_J2(T[k],i);
			printf("|");
			possibles_pion_J2(Cimetiere_IA,i);
			printf("|");
			for (k=19;k<24;k++)
				possibles_pion_J2(T[k],i);
			possibles_pion_J2(T[k],i);
			printf("|\\\n");
		}

		//Affichage milieu du plateau----------------------------------------------
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_mil_J2(T[k]);
		possibles_pion_mil_J2(T[k]);
		printf("|");
		possibles_pion_mil_J2(Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_mil_J2(T[k]);
		possibles_pion_mil_J2(T[k]);
		printf("|\\\n");
	
		printf("|            |  |            |\\\n");
	
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_mil_J2(T[k]);
		possibles_pion_mil_J2(T[k]);
		printf("|");
		possibles_pion_mil_J2(Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_mil_J2(T[k]);
		possibles_pion_mil_J2(T[k]);
		printf("|\\\n");
		//Affichage fin du milieu de plateau----------------------------------------
	
		for (i=4;i>1;i--)
		{
			printf("|");
			for (k=12;k>6;k--)
				possibles_pion_J2(T[k],i);
			printf("|");
			possibles_pion_J2(Cimetiere_U,i);
			printf("|");
			for (k=6;k>1;k--)
				possibles_pion_J2(T[k],i);
			possibles_pion_J2(T[k],i);
			printf("|\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_bas_J2(T[k],i);
		possibles_pion_J2(T[k],i);
		printf("|");
		possibles_pion_J2(Cimetiere_U,i);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_bas_J2(T[k],i);
		possibles_pion_J2(T[k],i);
		printf("|\\ Sortie: %d\n", Sortie_IA);
	}
	else printf("\nAucun utilisateur n'a ete selectione\n\n");

	//printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	printf(" T¯T¯T¯T¯T¯T¯T¯¯¯T¯T¯T¯T¯T¯T¯T\\\n");
	//Fin Affichage dernière ligne du plateau
	
	printf(" 12  10  8         5   3   1\n");
	printf("   11  9   7     6   4   2\n");
}



void display_pions_possibles_cim(int T[25],int joueur, int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	printf(" ____________________________\n");
	if (joueur == U1)
	{	
		printf("|%c'%c'%c'%c'%c'%c |", pion(T[13],1),pion(T[14],1), pion(T[15],1), pion(T[16],1), pion(T[17],1), pion(T[18],1));
		possibles_pion_J2(Cimetiere_IA,1);
		printf("|%c'%c'%c'%c'%c'%c |\\ Sortie : %d \n", pion(T[19],1),pion(T[20],1), pion(T[21],1), pion(T[22],1), pion(T[23],1), pion(T[24],1), Sortie_U);

		for (i=2; i<5; i++)
		{
			printf("|%c %c %c %c %c %c |", pion(T[13],i),pion(T[14],i), pion(T[15],i), pion(T[16],i), pion(T[17],i), pion(T[18],i));	
			possibles_pion_J2(Cimetiere_IA,i);
			printf("|%c %c %c %c %c %c |\\ \n", pion(T[19],i),pion(T[20],i), pion(T[21],i), pion(T[22],i), pion(T[23],i), pion(T[24],i));
		}

		printf("|");
		for (k=13;k<18;k++) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|");
		pion_mil(Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|\\\n");

		printf("|            |  |            |\\\n");

		printf("|");
		for (k=12;k>7;k--) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|");
		pion_mil(Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|\\\n");

		for (i=2; i<5; i++)
		{
			printf("|%c %c %c %c %c %c |", pion(T[12],4),pion(T[11],4), pion(T[10],4), pion(T[9],4), pion(T[8],4), pion(T[7],4));	
			possibles_pion_J2(Cimetiere_IA,i);
			printf(" |%c %c %c %c %c %c |\\ \n", pion(T[6],1),pion(T[5],1), pion(T[4],1), pion(T[3],1), pion(T[2],1), pion(T[1],1));
		}

		printf("|%c,%c,%c,%c,%c,%c |", pion(T[12],1),pion(T[11],1), pion(T[10],1), pion(T[9],1), pion(T[8],1), pion(T[7],1) );
		possibles_pion_J2(Cimetiere_U,1);
		printf("|%c,%c,%c,%c,%c,%c |\\ Sortie : %d \n", pion(T[6],1),pion(T[5],1), pion(T[4],1), pion(T[3],1), pion(T[2],1), pion(T[1],1), Sortie_IA);
	}
	else if (joueur == U2)
	{	
		printf("|%c'%c'%c'%c'%c'%c |", pion(T[13],1),pion(T[14],1), pion(T[15],1), pion(T[16],1), pion(T[17],1), pion(T[18],1));
		possibles_pion_J2(Cimetiere_IA,1);
		printf("|%c'%c'%c'%c'%c'%c |\\ Sortie : %d \n", pion(T[19],1),pion(T[20],1), pion(T[21],1), pion(T[22],1), pion(T[23],1), pion(T[24],1), Sortie_U);

		for (i=2; i<5; i++)
		{
			printf("|%c %c %c %c %c %c |", pion(T[13],i),pion(T[14],i), pion(T[15],i), pion(T[16],i), pion(T[17],i), pion(T[18],i));	
			possibles_pion_J2(Cimetiere_IA,i);
			printf("|%c %c %c %c %c %c |\\ \n", pion(T[19],i),pion(T[20],i), pion(T[21],i), pion(T[22],i), pion(T[23],i), pion(T[24],i));
		}

		printf("|");
		for (k=13;k<18;k++) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|");
		pion_mil(Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|\\\n");

		printf("|            |  |            |\\\n");

		printf("|");
		for (k=12;k>7;k--) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|");
		pion_mil(Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--) pion_mil(T[k]);
		pion_mil(T[k]);
		printf("|\\\n");

		for (i=2; i<5; i++)
		{
			printf("|%c %c %c %c %c %c |", pion(T[12],4),pion(T[11],4), pion(T[10],4), pion(T[9],4), pion(T[8],4), pion(T[7],4));	
			possibles_pion_J2(Cimetiere_IA,i);
			printf(" |%c %c %c %c %c %c |\\ \n", pion(T[6],1),pion(T[5],1), pion(T[4],1), pion(T[3],1), pion(T[2],1), pion(T[1],1));
		}

		printf("|%c,%c,%c,%c,%c,%c |", pion(T[12],1),pion(T[11],1), pion(T[10],1), pion(T[9],1), pion(T[8],1), pion(T[7],1) );
		possibles_pion_J2(Cimetiere_U,1);
		printf("|%c,%c,%c,%c,%c,%c |\\ Sortie : %d \n", pion(T[6],1),pion(T[5],1), pion(T[4],1), pion(T[3],1), pion(T[2],1), pion(T[1],1), Sortie_IA);
	}
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	printf(" 12  10   8         5   3   1\n");
	printf("   11  9    7     6   4   2\n");
}

void display_pions_possibles(int T[25], int joueur, int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	if ((Cimetiere_U != 0 && joueur == U1) || (Cimetiere_IA != 0 && joueur == U2))
		display_pions_possibles_cim(T, U1, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
	else
		display_pions_possibles_gen(T, U1, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
}


/*
void possibles_coups_haut_J1(int k,int i, int pos, int de1, int de2)
{	
	if (k == pos)
	{
		couleur("31");
		printf("X'");
		couleur("0");	
	}
	else if ((k != pos + de1 && k != pos + de2 && k != pos + de1 + de2) || T[k]<-1)
	{	
		if (i > abs(T[k]))
			printf(" '");
		else if (c>0)
			printf("O'");
		else
			printf("X'");
	}
	else
	{
		if (T[k] == -1)
		{
			couleur("35");
			printf("X'");
			couleur("0");
		}
	}
	else if (i == abs(k) && c<0) //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X'");
		//color(7,0);
		//Version portable
		//printf("A'");
		//Version Linux
		couleur("31");
		printf("X'");
		couleur("0");
	}
	else if (c>0)
		printf("O'");
	else
		printf("X'");
}

void possibles_coups_J1(int k,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(k))
		printf("  ");
	else if (i == abs(k) && c<0) //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X ");
		//color(7,0);
		//Version portable
		//printf("A ");
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else if (k>0)
		printf("O ");
	else
		printf("X ");
}

void possibles_coups_mil_J1(int c)
{	
	if (abs(k) < 5)
		printf("  ");
	else if (k == -5)  //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X ");
		//color(7,0);
		//Version portable
		//printf("A ");
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else if (k == 5)
		printf("O ");
	else if (k <= 10) //pion possible J1 >= 10
	{
		//Version Windows
		//color(12,0);
		//printf("1%c",c%10+48);
		//color(7,0);
		//Version portable
		//printf("A%c",c%10+48);
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else if (k >= 10)
		printf("1%c",c%10+48);
	else if(k < -5 )   //pion possible J1 entre 5 et 10 
	{
		//Version Windows
		//color(12,0);
		//printf("%c ",c+48);
		//color(7,0);
		//Version portable
		//printf("%cA",c+48);
		//Version Linux
		couleur("31");
		printf("X ");
		couleur("0");
	}
	else
		printf("%c ",c+48);
}

void possibles_coups_bas_J1(int k,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(k))
		printf(" ,");
	else if (i == abs(k) && c<0) //pion possible J1
	{
		//Version Windows
		//color(12,0);
		//printf("X,");
		//color(7,0);
		//Version portable
		//printf("A,");
		//Version Linux
		couleur("31");
		printf("X,");
		couleur("0");
	}
	else if (c>0)
		printf("O,");
	else
		printf("X,");
}

void possibles_coups_haut_J2(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf(" '");
	else if (i == abs(c) && c>0) //pion possible J2
	{
		//Version Windows
		//color(5,0);  
		//printf("O'");
		//color(7,0);
		//Version portable
		//printf("Q'");
		//Version Linux
		couleur("32");
		printf("O'");
		couleur("0");
	}
	else if (c>0)
		printf("O'");
	else
		printf("X'");
}

void possibles_coups_J2(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf("  ");
	else if (i == abs(c) && c>0) //pion possible J2
	{
		//Version Windows
		//color(5,0);
		//printf("O ");
		//color(7,0);
		//Version portable
		//printf("Q ");
		//Version Linux
		couleur("32");
		printf("O ");
		couleur("0");
	}
	else if (c>0)
		printf("O ");
	else
		printf("X ");
}

void possibles_coups_mil_J2(int c)
{	
	if (abs(c) < 5)
		printf("  ");
	else if (c == -5)
		printf("X ");
	else if (c == 5)   //pion possible J2
	{
		//Version Windows
		//color(5,0);
		//printf("O ");
		//color(7,0);
		//Version portable
		//printf("Q ");
		//Version Linux
		couleur("32");
		printf("O ");
		couleur("0");
	}
	else if (c <= 10)
		printf("1%c",c%10+48);
	else if (c >= 10)  //pion possible J2 >= 10
	{
		//Version Windows
		//color(5,0);
		//printf("1%c",c%10+48); 
		//color(7,0);
		//Version portable
		//printf("Q%c",c%10+48); 
		//Version Linux
		couleur("32");
		printf("O ");
		couleur("0");
	} 
	else if(c < -5 )
		printf("%c ",c+48);
	else    //pion possible J2 entre 5 et 10
	{
		//Version Windows
		//color(5,0);
		//printf("%c ",c+48);
		//color(7,0);
		//Version portable
		//printf("%cQ",c+48);	
		//Version Linux
		couleur("32");
		printf("O ");
		couleur("0");
	}		 
}

void possibles_coups_bas_J2(int c,int i) //Renvoie un char représentant un pion IA 0
{									//un pion adversaire X, ou le vide		
	if (i > abs(c))
		printf(" ,");
	else if (i == abs(c) && c>0) //pion possible J2
	{
		//Version Windows
		//color(5,0);
		//printf("O,");
		//color(7,0);
		//Version portable
		//printf("Q,");
		//Version Linux
		couleur("32");
		printf("O,");
		couleur("0");
	}
	else if (c>0)
		printf("O,");
	else
		printf("X,");
}


void display_coups_possibles(int T[25], int joueur,int position, int de1, int d2, int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	//Affichage première ligne du plateau
	printf(" ____________________________\n");
	
	if (joueur == 1)
	{
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_haut_J1(k,1);
		possibles_pion_J1(k,1);
		printf("|");
		possibles_pion_J1(Cimetiere_IA,i);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_haut_J1(k,1);
		possibles_pion_J1(k,1);
		printf("|\\	Sortie : %d\n", Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
				possibles_pion_J1(k,i);
			printf("|");
			possibles_pion_J1(Cimetiere_IA,i);
			printf("|");
			for (k=19;k<24;k++)
				possibles_pion_J1(k,i);
			possibles_pion_J1(k,i);
			printf("|\\\n");
		}

		//Affichage milieu du plateau----------------------------------------------
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_mil_J1(k);
		possibles_pion_mil_J1(k);
		printf("|");
		possibles_pion_mil_J1(Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_mil_J1(k);
		possibles_pion_mil_J1(k);
		printf("|\\\n");
	
		printf("|            |  |            |\\\n");
	
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_mil_J1(k);
		possibles_pion_mil_J1(k);
		printf("|");
		possibles_pion_mil_J1(Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_mil_J1(k);
		possibles_pion_mil_J1(k);
		printf("|\\\n");
		//Affichage fin du milieu de plateau----------------------------------------
	
		for (i=4;i>1;i--)
		{
			printf("|");
			for (k=12;k>6;k--)
				possibles_pion_J1(k,i);
			printf("|");
			possibles_pion_J1(Cimetiere_U,i);
			printf("|");
			for (k=6;k>1;k--)
				possibles_pion_J1(k,i);
			possibles_pion_J1(T[k],i);
			printf("|\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_bas_J1(k,i);
		possibles_pion_J1(k,i);
		printf("|");
		possibles_pion_J1(Cimetiere_U,i);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_bas_J1(k,i);
		possibles_pion_J1(k,i);
		printf("|\\ Sortie: %d\n", Sortie_IA);
	}




	else if (joueur == 2)
	{
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_haut_J2(k,1);
		possibles_pion_J2(k,1);
		printf("|");
		possibles_pion_J2(Cimetiere_IA,i);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_haut_J2(k,1);
		possibles_pion_J2(k,1);
		printf("|\\	Sortie : %d\n", Sortie_U);
		//Fin Affichage première ligne du plateau
	
	
		for (i=2;i<5;i++)
		{
			printf("|");
			for (k=13;k<19;k++)
				possibles_pion_J2(k,i);
			printf("|");
			possibles_pion_J2(Cimetiere_IA,i);
			printf("|");
			for (k=19;k<24;k++)
				possibles_pion_J2(k,i);
			possibles_pion_J2(k,i);
			printf("|\\\n");
		}

		//Affichage milieu du plateau----------------------------------------------
		printf("|");
		for (k=13;k<18;k++)
			possibles_pion_mil_J2(k);
		possibles_pion_mil_J2(k);
		printf("|");
		possibles_pion_mil_J2(Cimetiere_IA);
		printf("|");
		for (k=19;k<24;k++)
			possibles_pion_mil_J2(k);
		possibles_pion_mil_J2(T[k]);
		printf("|\\\n");
	
		printf("|            |  |            |\\\n");
	
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_mil_J2(k);
		possibles_pion_mil_J2(k);
		printf("|");
		possibles_pion_mil_J2(Cimetiere_U);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_mil_J2(k);
		possibles_pion_mil_J2(k);
		printf("|\\\n");
		//Affichage fin du milieu de plateau----------------------------------------
	
		for (i=4;i>1;i--)
		{
			printf("|");
			for (k=12;k>6;k--)
				possibles_pion_J2(k,i);
			printf("|");
			possibles_pion_J2(Cimetiere_U,i);
			printf("|");
			for (k=6;k>1;k--)
				possibles_pion_J2(k,i);
			possibles_pion_J2(k,i);
			printf("|\\\n");
		}
		
		//Affichage dernière ligne du plateau
		printf("|");
		for (k=12;k>7;k--)
			possibles_pion_bas_J2(k,i);
		possibles_pion_J2(k,i);
		printf("|");
		possibles_pion_J2(Cimetiere_U,i);
		printf("|");
		for (k=6;k>1;k--)
			possibles_pion_bas_J2(k,i);
		possibles_pion_J2(k,i);
		printf("|\\ Sortie: %d\n", Sortie_IA);
	}
	else printf("\nAucun utilisateur n'a ete selectione\n\n");

	//printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	printf(" ¯T¯T¯T¯T¯T¯T¯¯¯T¯T¯T¯T¯T¯T¯T\\\n");
	//Fin Affichage dernière ligne du plateau
	
	printf(" 12  10  8         5   3   1\n");
	printf("   11  9   7     6   4   2\n");
}
*/

void afficher(int T[26])
{
	int i;
	
	for (i=0;i<13;i++)
		printf("%d: %d    %d: %d\n",i,T[i],i+13,T[i+13],T[i+13]);
	printf("\n");
}

void initialiser_pions_plateau(int T[25])
{
	T[1]=-2;
	T[6]=5;
	T[8]=3;
	T[12]=-5;
	T[13]=5;
	T[17]=-3;
	T[19]=-5;
	T[24]=2;
}

/*
int lancer_de1(void)
{
    int i = 0;
    int nombre_aleatoire = 0;
    
    srand(time(NULL)); // initialisation de rand
	nombre_aleatoire = rand()%6+1;
    return nombre_aleatoire;
}

int lancer_de2(void)
{
    int i = 0;
    int nombre_aleatoire = 0;
    
    srand(time(NULL)+5); // initialisation de rand
	nombre_aleatoire = rand()%6+1;
    return nombre_aleatoire;
}

int choix_coup(int T[25],int joueur,int de1, int de2)
{
	int position,somme;

	somme=de1+de2;
	do
	{
		printf("Entrez la position du premier pion que vous voulez déplacer:");
		scanf("%d",&position);
		printf("\n");
	}
	while (T[position] <= 0);
	printf("\n\n");
	return position;
}

//  display avec uniquement le joueur 1
void display_pions_possibles(int T[25], int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	//Affichage première ligne du plateau
	printf(" ____________________________\n");
	
	printf("|");
	for (k=13;k<18;k++)
	{
		printf("%c'",possibles_pion(T[k],1));
	}
	printf("%c ",possibles_pion(T[k],1));
	printf("|%c |",possibles_pion(Cimetiere_IA,1));
	for (k=19;k<24;k++)
	{
		printf("%c'",possibles_pion(T[k],1));
	}
	printf("%c ",possibles_pion(T[k],1));
	printf("|\\	Sortie : %d\n", Sortie_U);
	//Fin Affichage première ligne du plateau
	
	
	for (i=2;i<5;i++)
	{
		printf("|");
		for (k=13;k<19;k++)
		{
			printf("%c ",possibles_pion(T[k],i));
		}
		printf("|%c |",possibles_pion(Cimetiere_IA,i));
		for (k=19;k<24;k++)
		{
			printf("%c ",possibles_pion(T[k],i));
		}
		printf("%c ",possibles_pion(T[k],i));
		printf("|\\\n");
	}

	//Affichage milieu du plateau----------------------------------------------
	printf("|");
	for (k=13;k<18;k++)
	{
		possibles_pion_mil(T[k]);
	}
	possibles_pion_mil(T[k]);
	printf("|");
	possibles_pion_mil(Cimetiere_IA);
	printf("|");
	for (k=19;k<24;k++)
	{
		possibles_pion_mil(T[k]);
	}
	possibles_pion_mil(T[k]);
	printf("|\\\n");

	printf("|            |  |            |\\\n");

	printf("|");
	for (k=12;k>7;k--)
	{
		possibles_pion_mil(T[k]);
	}
	possibles_pion_mil(T[k]);
	printf("|");
	possibles_pion_mil(Cimetiere_U);
	printf("|");
	for (k=6;k>1;k--)
	{
		possibles_pion_mil(T[k]);
	}
	possibles_pion_mil(T[k]);
	printf("|\\\n");
	//Affichage fin du milieu de plateau----------------------------------------
	
	for (i=4;i>1;i--)
	{
		printf("|");
		for (k=12;k>6;k--)
		{
			printf("%c ",possibles_pion(T[k],i));
		}
		printf("|%c |",possibles_pion(Cimetiere_U,i));
		for (k=6;k>1;k--)
		{
			printf("%c ",possibles_pion(T[k],i));
		}
		printf("%c ",possibles_pion(T[k],i));
		printf("|\\\n");
	}
	
	//Affichage dernière ligne du plateau
	printf("|");
	for (k=12;k>7;k--)
	{
		printf("%c,",possibles_pion(T[k],i));
	}
	printf("%c ",possibles_pion(T[k],i));
	printf("|%c |",possibles_pion(Cimetiere_U,i));
	for (k=6;k>1;k--)
	{
		printf("%c,",possibles_pion(T[k],i));
	}
	printf("%c ",possibles_pion(T[k],i));
	printf("|\\ Sortie: %d\n", Sortie_IA);
	
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	//Fin Affichage dernière ligne du plateau
	
	printf(" 12 10   8         5   3   1\n");
	printf("   11  9   7     6   4   2\n");
}


void en plus long
void display(int T[25], int Cimetiere_IA, int Cimetiere_U, int Sortie_IA, int Sortie_U)
{
	int k,i; //k: case du pion|i: hauteur du pion dans sa case
	
	k=13;
	printf("   14  16  18    19  21  23\n");
	printf(" 13  15  17        20  22  24\n");
	//Affichage première ligne du plateau
	printf(" ____________________________\n");
	
	printf("|");
	for (k=13;k<18;k++)
	{
		printf("%c'",pion(T[k],1));
	}
	printf("%c ",pion(T[k],1));
	printf("|%c |",pion(Cimetiere_IA,1));
	for (k=19;k<24;k++)
	{
		printf("%c'",pion(T[k],1));
	}
	printf("%c ",pion(T[k],1));
	printf("|\\	Sortie : %d\n", Sortie_U);
	//Fin Affichage première ligne du plateau
	
	
	for (i=2;i<5;i++)
	{
		printf("|");
		for (k=13;k<19;k++)
		{
			printf("%c ",pion(T[k],i));
		}
		printf("|%c |",pion(Cimetiere_IA,i));
		for (k=19;k<24;k++)
		{
			printf("%c ",pion(T[k],i));
		}
		printf("%c ",pion(T[k],i));
		printf("|\\\n");
	}

	//Affichage milieu du plateau----------------------------------------------/
	printf("|");
	for (k=13;k<18;k++)
	{
		pion_mil(T[k]);
	}
	pion_mil(T[k]);
	printf("|");
	pion_mil(Cimetiere_IA);
	printf("|");
	for (k=19;k<24;k++)
	{
		pion_mil(T[k]);
	}
	pion_mil(T[k]);
	printf("|\\\n");

	printf("|            |  |            |\\\n");

	printf("|");
	for (k=12;k>7;k--)
	{
		pion_mil(T[k]);
	}
	pion_mil(T[k]);
	printf("|");
	pion_mil(Cimetiere_U);
	printf("|");
	for (k=6;k>1;k--)
	{
		pion_mil(T[k]);
	}
	pion_mil(T[k]);
	printf("|\\\n");
	//Affichage fin du milieu de plateau----------------------------------------/
	
	for (i=4;i>1;i--)
	{
		printf("|");
		for (k=12;k>6;k--)
		{
			printf("%c ",pion(T[k],i));
		}
		printf("|%c |",pion(Cimetiere_U,i));
		for (k=6;k>1;k--)
		{
			printf("%c ",pion(T[k],i));
		}
		printf("%c ",pion(T[k],i));
		printf("|\\\n");
	}
	
	//Affichage dernière ligne du plateau
	printf("|");
	for (k=12;k>7;k--)
	{
		printf("%c,",pion(T[k],i));
	}
	printf("%c ",pion(T[k],i));
	printf("|%c |",pion(Cimetiere_U,i));
	for (k=6;k>1;k--)
	{
		printf("%c,",pion(T[k],i));
	}
	printf("%c ",pion(T[k],i));
	printf("|\\ Sortie: %d\n", Sortie_IA);
	
	printf(" TTTTTTTTTTTTTTTTTTTTTTTTTTTT\\\n");
	//Fin Affichage dernière ligne du plateau
	
	printf(" 12 10   8         5   3   1\n");
	printf("   11  9   7     6   4   2\n");
}
*/


/*-------------------------------------------------------------------------------*/
/*                                     MAIN                                      */
/*-------------------------------------------------------------------------------*/

/*
int T[25]={0};
int main(void)
{
	int T[26]={{0},{0}};
	int de1,de2,position,fin;
	int *trajet;
	
	fin=0;
	initialiser_plateau(T);
	printf("----------LA PARTIE COMMENCE---------\n\n");
	display(T);
	printf("Vous êtes le joueur BLANC, vos pions sont les O.");
	
	do 
	{

		printf(">Vous lancez les dés:");
		de1=lancer_de1();
		de2=lancer_de2();
		printf("Vous avez obtenu %d et %d\n",de1,de2);
		
		choix_trajet(T,)
		position=choix_pos(T,0);


		if (fin)
		{
			printf(">Le joueur ROUGE lance les dés:");
		}
	}
	while (fin);	
	return 0;
}
*/


int main(void)
{
	int T[25]={0};
	int de1,de2,position,fin;
	int Cimetiere_IA = 0;
	int Cimetiere_U = 1;
	int Sortie_IA = 0;
	int Sortie_U = 0;

	fin=0;
	initialiser_pions_plateau(T);
	printf("----------LA PARTIE COMMENCE---------\n\n");
	//display(T,&Cimetiere_IA, &Cimetiere_U, &Sortie_IA, &Sortie_U);
	display_pions_possibles(T, U1, Cimetiere_IA, Cimetiere_U, Sortie_IA, Sortie_U);
	return 0;
}


/*
int main(void)
{
	printf("\033[H\033[2J");

	couleur("31");
	printf("test");
	couleur("0");
	printf("test\n");

	return 0;
}
*/