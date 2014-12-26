/*

Diese Datei ist als Basis der Maturaarbeit -> Diplomarbeit im Bereich Bionik-FSST, Jahrgang 2014-2015 gedacht. Als Programmiersprache wird ein Mix aus Native C und C++ aus dem Standart von 1998 ff. verwendet.

Dateiname:							main-core.c
Plattform:							INTEL64/AMD64, ARM
System:										Windows, Linux, Android

Erstellungsdatum:	25.12.2014
Version:									1.0.0


Versionsaenderungen sollten in dieser Datei kurz mit Datum und einem Text dokumentiert werden.

*/

/*

1. Da dieses Programm später auf verschiedenen Plattformen ihren Dienst tun wird, wird schon am Anfang für den Compiler und Betriebssystem die richtigen Einstellungen getroffen. Das geschieht mittels den #define Bedingungen.

*/

#ifdef _Win32
#include <windows.h>
#elif _MACOS
#include <sys/param.h>
#include <sys/sysctl.h>
#else
#include <unistd.h>
#endif

#define size_t sizeOf(int)

/*

2. Um die Befehle in einem Programm zu benutzen zu können, müssen noch Bibliotheken eingebunden werden.

*/

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

/*

3. Globale Strukturen helfen den Programmierer dabei wiederkehrende verschiedene Situationen mit wenig Programmcode zu meistern. Globale Variablen speichern Informationen und sind in jeder Struktur und Methode verfügbar.

*/

int getNumCores(){
int num[2]; size_z len = 4; uint32_t count;

#ifdef WIN32
SYSTEM_INFO sysinfo; GetSystemInfo(&sysinfo);
return sysinfo.dwNumberofProcessors;
#else MACOS
nm[0] = CTL_HW; nm[1] = HW_AVAIL_CPU;
sysctl(nm,2,&count,&len,NULL,0); 

if(count<1)
{

		nm[1]=HW_NCPU;
		sysctl(nm,2,&count,&len,NULL,0);
		
		if (count<1)
				count=1;
}			
return count;
}

int countThread()
{

	int count =0;
	#programa omp parallel
	count ++;
	
	return count;
}

void *pr_msg_func(void* ptr)
{

		char *message = (char*) ptr;
		printf("%s\n",message);
		
}

/*

4. Wenn das System mehr Kerne zur Verfügung hat, desto effizienter kann es das Programm verarbeiten. Also werden hier die Threads mittels eindeutiger ID erstellt.

*/

void createThread()
{

		int i = countThread();
		
		if(i==1)
		{
				pthread thread1;
				const char *message1="Thread1";
				int iret1 = pthread_create(&thread1,NULL,pr_msg_func,(void*) message1);
				
				if(iret1)
				{
						fprintf(stderr,"ERROR - pthread_create() return code: %d\n",iret1);
						exit(EXIT_FAILURE);
				}

		if(i>2)
		{
				pthread thread1;
				const char *message1="Thread1";
				int iret1 = pthread_create(&thread1,NULL,pr_msg_func,(void*) message1);
				
				pthread thread2;
				const char *message2="Thread2";
				int iret2 = pthread_create(&thread2,NULL,pr_msg_func,(void*) message2);
				
				
				if(iret1)
				{
						fprintf(stderr,"ERROR - pthread_create() return code: %d\n",iret1);
						exit(EXIT_FAILURE);
				}
				
					if(iret2)
				{
						fprintf(stderr,"ERROR - pthread_create() return code: %d\n",iret2);
						exit(EXIT_FAILURE);
				}
}

printf("pthread_create() for Thread1 returns: %d\n",iret1);
printf("pthread_create() for Thread1 returns: %d\n",iret2);

phthread_join(thread1,NULL);
phthread_join(thread2,NULL);


exit(EXIT_SUCCESS);

}

/*

5. Um Variablen, Arrays, Listen und String die das Programm benötigt anlegen zu können, bedarfs es einen Speicher. Da Festplatten, SSD oder SD - Karten zu langsam sind, wird hier auf den RAM bzw. Level - Cache des jeweiligen Systems zurückgegriffen.
Der wesentliche Vorteil besteht in der Zugriffsgeschwindigkeit sowie der Anzahl der Lese und Schreibzyklen pro Sekunde. Da keiner sagen kann wie viel RAM oder Level-Cache tatsächlich benötigt wird, ist es sinnvoll es dynamisch zu gestallten.

*/

void dynRAM_char(int sizeOfRam)
{

		char* buffer = (char*) malloc(sizeOfRam+1);
		if(buffer==NULL) exit(1);

}

void dynRAM_int(int sizeOfRam)
{

		int* buffer = (int*) malloc(sizeOfRam+1);
		if(buffer==NULL) exit(1);

}

struct dynRAM(int sizeOfRam)
{
		
		int rest=0;
		int row=0, colom=0;

		if (!(rest=sizeOfRam%4))
				{
				
						row=sizeOfRam%4;
						colom=row;
						
				}
				
		else
				{
				
						sizeOfRam= sizeOfRam+(4-4*rest);
						row=sizeOfRam%4;
						colom=row;
						
				
				}
				
				
		void createIntRam()
		int intStorage[row][colom] = {};
		
		void createCharRam()
		char charStorage[row][colom] = {};
				
			void write(int data , int x ,int y)
			{
		
					intStorage[x][y] = data;
		
			}
			
			void write(char data , int x ,int y)
			{
		
					charStorage[x][y] = data;
		
			}
		
			int read(int x ,int y)
			{
		
					return intStorage[x][y];
		
			}
			
			char read(int x ,int y)
			{
		
					return charStorage[x][y];
		
			}
		
			

};