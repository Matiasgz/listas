/*   RULETA RUSA   */


/*  ANALIZAR EL PROGRAMA  */

/*  CONSTRUIR LA FUNCION RUSA()   */
/*  1.   ESTA DEBE MOSTRAR LA LISTA DE PARTICIPANTES  */
/*  2.   GENERAR UN VALOR ALEATORIO N ENTRE 100 Y 200   */
/*  3.   AVANZAR EN LA LISTA N LUGARES MOSTRANDO LOS NOMBRES */
/*  4.   MOSTRAR EL NOMBRE ALCANZADO    */
/*  5.   ELIMINARLO  */
/*  6.   REPETIR EL PROCESO HASTA QUE SOLO QUEDE UN PARTICIPANTE */
/*  7.   MOSTRAR EL NOMBRE DEL GANADOR  */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

class NODO {
	public :
			NODO(char *) ;
			~NODO() ;
			char NOM[20] ;
			NODO * SIG ;	
};


NODO::NODO(char * S)
{
		strcpy ( NOM , S );
}

NODO::~NODO()
{
		cout << "\n\n   MATANDO A ... " << NOM ;
		getchar();
}



class LISTA {
	private :
			NODO * INICIO ;
			int CERRADA ;
			void PONER_F(NODO *) ;
	public :
			LISTA() ;
			~LISTA() ;
			void AGREGAR_F ( char * );
			void CERRAR() ;
			void MIRAR() ;
			void RUSA() ;
};


LISTA::LISTA()
{
		INICIO = NULL ;
		CERRADA = 0 ;
}

LISTA::~LISTA()
{
		cout << "\n\n   MATANDO A ... TODOS LOS NODOS" ;
		cout << "\n\n   ESTA ES PARA USTEDES" ;
		getchar();
}



void LISTA::AGREGAR_F( char * S )
{
		NODO * P ;
		P = new NODO(S) ;  
		
		PONER_F(P) ;	
}

void LISTA::PONER_F( NODO * PN) 
{
		NODO * P ;
		P = INICIO ;
		
		PN->SIG = NULL ;
		
		if ( ! INICIO ) {
				/*  LISTA VACIA  */
				INICIO = PN ;
				return ;			
		}
		/*   LISTA NO VACIA   */
		while ( P->SIG )
				P = P->SIG ; 		/*  LLEVO P HASTA EL ULTIMO NODO  */		
		P->SIG = PN ;
}

void LISTA::CERRAR()
{
		if (CERRADA || ! INICIO )
				return ;
		NODO * P ;
		P = INICIO ;
		
		while ( P->SIG )
				P = P->SIG ; 				
		P->SIG = INICIO ;
		CERRADA = 1 ;				
}


void LISTA::MIRAR()
{
		NODO * P ;
		P = INICIO ;
		
		cout << "\n\n\n\t CONTENIDO DE LA LISTA\n";
		while ( P ) {
				cout << "\n\n\t " << P->NOM ;
				getchar();
				P = P->SIG ;
		}
		getchar();
}

void LISTA::RUSA()
{
	
	NODO * P ;
	P = INICIO ;
		printf("\n\n\n\t RULETA RUSA \n");
	while (P->SIG != P){
		

	
	P = INICIO ;
	int N = 100 + rand()%101;
	int I = 0 ;
	while ( I < N-1 ) {
		P = P->SIG ;
		I++;	
	}
	printf("\n\n\t Nombre a borrar: %s", (P->SIG)->NOM);
	P->SIG = P->SIG->SIG ;
	
	}
	printf("\n\n\n\t GANADOR: %s", P->NOM);
	INICIO = P ;
	
	
	
	
}

char * GENERANOM();

int main( )
{  
		LISTA L ;
		char BUF[20];
		
		strcpy ( BUF , GENERANOM());
		while ( strcmp(BUF,"FIN") ) {
				L.AGREGAR_F(BUF) ;
				strcpy ( BUF , GENERANOM());
		}
		L.CERRAR();	
	//	L.MIRAR() ;
		
		L.RUSA() ;
		L.MIRAR() ;
		
		printf("\n\n");
		return 0 ;
}


char * GENERANOM()
{
	static int I = 0 ;
	static char NOM[][20] = {"DARIO","CAROLINA","PEPE","LOLA",
						     "PACO","LUIS","MARIA","ANSELMO",
						  	 "ANA","LAURA","PEDRO","ANIBAL",
						     "PABLO","ROMUALDO","ALICIA","MARTA",
						     "MARTIN","TOBIAS","SAUL","LORENA","FIN"};
	return NOM[I++] ;
	
}
