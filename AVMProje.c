#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

typedef struct{
	char kullanici_adi[20];
	char TCKimlik[12];
	char adsoyad[30];
	char cinsiyet[10];
	char Sifre[15];
	char calistigiMagaza[30];
	int yas;
	float maas;
	char Dogrulama[20];
	char DogumGunu[10];
    struct IndirimKarti{
    	float Puan;
	} IndirimKarti;
	struct{
		char Sikayet[100];
		char Oneri[100];
	}SikayetveOneri;
	struct{
		char E_Posta[50];
	}Iletisim;
	struct{
		int tatilsayisi;
		int tatiller[365][3];
	}tatil;
}Personel;

typedef struct{
	char kullanici_adi[20];
	char TCKimlik[12];
	char adsoyad[30];
	char cinsiyet[10];
	char Sifre[10];
	int yas;
	float maas;
	char Dogrulama[20];
	char DogumGunu[10];
    struct{
    	float Puan[10];	
	} IndirimKarti;
	struct{
		char E_Posta[50];
	}Iletisim;
}Yonetici;

typedef struct {
	char *Magazaper;
	char Magazakimlik[50];
	char Magazaisim[50];
	char Sektor[50];
	char KimlikSorgulama[50];
	int sec;
	struct {
	    float Satis[12];
	}Gelir;
	struct{
	    float Kira;
	    float alan;
    	struct {
		  	float Toptan[12];
		  	float Elektrik;
		  	float Dogalgaz;
		  	float Su;
		}Fatura;
	    float Toplam;	
	}Gider;	
	struct{
		int *boyut;
		int magazasayisi[1000];
		int tipadet[1];
	}Yapi;	
	struct{
		int tatilsayisi;
		int tatiller[365][3];
		int aydinlatmaderecesi;
	}saatler;
}Magaza;
	
typedef struct{
	char kullanici_adi[20];
	char KimlikNo[12];
	char Ad[20];
	char Soyad[20];
	char Sifre[15];
	char Dogrulama[20];
	char DogumGunu[10];
    struct{
    	float Puan;	
	} IndirimKarti;
	struct{
		char Sikayet[100];
		char Oneri[100];
	}SikayetveOneri;
	struct{
		char Telefon[14];
		char E_Posta[50];
	}Iletisim;
}Musteri;

typedef struct{
	char kampanyakodu[100];
	char kampanyaadi[100];
	char kampanyabilgi[100];
}kmp;

typedef struct{
	int maxkisi;
	int minkisi;	
}gc;
	
	kmp kampanya;
	Personel per;
	Yonetici yon;
	Magaza Boyut;
	Musteri cust;
	gc kisi;
	
void AnaMenu();
void indirkartSayfa();
void yogunlukHesap();
void puanGirdi();
int secim=0;
void MusteriEkran();
void MusteriKayit();
void SifremiUnuttum();
void SikayetVeOneri();
void MusteriGiris();
void MusteriKayitSil();
void MusteriBilgileri(char ARA[]);
void MusteriAnasayfa();
void MagazaMusterileri();
void SikayetVeOneriGoster();
void PersonelKayit();
void SifremiUnuttum2();
void SikayetVeOneri2();
void PersonelSayfa();
void PersonelGiris();
void PersonelKayitSil();
void PersonelBilgileri(char ARA[]);
void PersonelAnasayfa();
void MagazaPersonelleri();
void SikayetVeOneriGoster2();
void MagazaMenu();
void MagazayiGoster();
void MagazaKiralama();
void MagazaKayit();
void MagazaYapilandirma();
void isiklandirma();
void tatiller();
void YonetimKayit();
void YonetimKayitSil();
void YonetimAnasayfa();
void PersonelEkran();
void izingunleri();
void KampanyaEkle();
void KampanyaSil();
void KampanyaGoruntulemeMusteri();
void KampanyaGoruntulemePersonel();
void KampanyaAnaSayfa();
void puanGirdi();
void yogunlukHesap();

int main(){
	setlocale(LC_ALL,"Turkish");
    AnaMenu();
}

void MusteriSayisi()
{
	FILE *kisisayisi=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\KisiSayisi\\kisisayisi.txt","w+");
	int i;
	for(i=0;i<80;i++){printf("_");}printf("\n");
	printf("      PANDEM� KO�ULLARI ���N AVM YO�UNLU�U\n");
	for(i=0;i<80;i++){printf("_");}printf("\n");
	printf("AVM i�in maksimum kapasite giri�i yap�n�z: ");
	scanf("%d",&kisi.maxkisi);
	printf("AVM i�in minimum kapasite giri�i yap�n�z: ");
	scanf("%d",&kisi.minkisi);
	fwrite(&kisi,sizeof(kisi),1,kisisayisi);
	fclose(kisisayisi);
	printf("AVM'ye %d maksimum ki�i %d minimum ki�i girebilir.\n\n",kisi.maxkisi,kisi.minkisi);	
	printf("AVM Y�netim Sayfas�na Yeniden y�nlendiriliyorsunuz...\n");
	sleep(4);
	YonetimAnasayfa();
}

void yogunlukHesap()
{
	int i, j, s;
	int k=4;
	int l=7;
	int diziH[7];
	long int **matris;
	int degis;
	degis = time(NULL);
	srand(degis);
	float gunlukortaHepsi=0;
	float gunlukortHafta=0;
	
	FILE *kisisayisi=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\KisiSayisi\\kisisayisi.txt","r");
	if(kisisayisi==NULL){
		printf("\n\nMA�AZA HEN�Z A�ILMAMI�TIR.\nYay�n Ak���n� Takip edebilmek i�in Ma�aza Y�netimiyle ileti�ime ge�iniz.\nAna Men�ye tekrar y�nlendiriliyorsunuz...\n");
		sleep(5);
		AnaMenu();
	}
	else{
		while(fread(&kisi,sizeof(kisi),1,kisisayisi)==1){
			system("cls");
			printf("\nYAYIN AKI� SAYFASI\n");
		
		
		for(i=0;i<50;i++){ printf("_");} printf("\n");
		printf("Sondan ka� hafta g�r�nt�lensin ? (en fazla 7)_(varsay�lan 4): ");
		scanf("%d",&k);
	
		matris = (long int **)malloc( l * sizeof(long int) );
		if( matris == NULL){
			printf("Maalesef Yetersiz bellek!");}
			for( i = 0; i < l; i++ ){
				matris[i] = (long int *)malloc( k * sizeof(long int) );
				if( matris[i] == NULL)
				printf("Maalesef Yetersiz bellek!");
			}
			for(i=0;i<50;i++){ printf("_");} printf("\n");
			for(i=0;i<k;i++){
				for(j=0;j<7;j++){
					matris[i][j]=rand()%(1000-kisi.minkisi)+kisi.minkisi;
					if(matris[i][j]>kisi.maxkisi){
						matris[i][j]=kisi.maxkisi;
						printf(" %d  ",matris[i][j]);
					}
					else{
						printf(" %d  ",matris[i][j]);
					}
				}
				printf("\n");
			}
			for(i=0;i<50;i++){ printf("_");} printf("\n");
			printf("\n");
			for(i=0;i<50;i++){ printf("_");} printf("\n");
			
			printf("Haftalara g�re g�nl�k yo�unluk ortalamas�:\n");
			for(i=0;i<k;i++){
				for(j=0;j<7;j++){
					gunlukortHafta+=(float)(matris[i][j]);
				}
			gunlukortHafta=gunlukortHafta/7;
			gunlukortHafta=gunlukortHafta/10;
			printf("%d) hafta :  %%%.2f  ",(i+1), gunlukortHafta);
			printf("\n");
			gunlukortHafta=0;
			}
			printf("\n");
			printf("Toplam g�nl�k yo�unluk ortalamas�:");
			
			for(i=0;i<k;i++){
				for(j=0;j<7;j++){
					gunlukortaHepsi+=(float)(matris[i][j]);	
				}	
			}
			printf("\n");
			gunlukortaHepsi=( gunlukortaHepsi/(k*7) );
			gunlukortaHepsi=gunlukortaHepsi/10;
			printf("Genel ortalama: %%%.2f\n",gunlukortaHepsi);
			
			for(i=0;i<50;i++){ printf("_");} printf("\n");
	
			printf("\n\n��kmak i�in E, yeniden bakmak i�in H giriniz: ");
			fflush(stdin);
			if(toupper(getch())== 'H'){
				printf("\n\n");
				yogunlukHesap();
			}
			else if(toupper(getch())== 'E'){
				printf("\n\n");
			}
			sleep(1);
			exit(1);
	    }
	}
}


void KampanyaEkle(){
	int i;
	system("cls");
	for(i=0;i<100;i++){ printf("_");} printf("\n");
	printf("\n           KAMPANYA EKLEME EKRANI\n");
	for(i=0;i<100;i++) {printf("_");} printf("\n");
	a:
	printf("\nKampanya kodunu olu�turun: ");
		scanf("%s",kampanya.kampanyakodu);
   		strcat(kampanya.kampanyakodu,".txt");
    	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\";
    	strcat(dosyauzantisi,kampanya.kampanyakodu);
		FILE *kampanyadosya=fopen(dosyauzantisi,"r");
		if(kampanyadosya==NULL){
			fclose(kampanyadosya);
			kampanyadosya=fopen(dosyauzantisi,"w");
			printf("Kampanyaya ba�l�k giriniz: ");
			fflush(stdin);
			gets(kampanya.kampanyaadi);
			printf("Kampanya bilgileri giriniz(Bo�luk yerine _ kullan�n�z): ");
			fflush(stdin);
			gets(kampanya.kampanyabilgi);
			printf("Kampanyan�n Durumunu belirleyiniz.\n[1] Kampanya Personeller i�in ise\n[2] Kampanya Genele A��k ise\nGiriniz: ");
			scanf("%d",&i);
			fwrite(&kampanya,sizeof(kampanya),1,kampanyadosya);
			fclose(kampanyadosya);
			printf("\nKampanyan�z olu�turulmu�tur!\n Ana Men�ye y�nlendiriliyorsunuz...\n\n");
			
			if(i==1){
				FILE *kampanyaozel=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiOzel.txt","a+");
				fwrite(&kampanya,sizeof(kampanya),1,kampanyaozel);
				fclose(kampanyaozel);
			}
			else if(i==2){
				FILE *kampanyagenel=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt","a+");
				fwrite(&kampanya,sizeof(kampanya),1,kampanyagenel);
				fclose(kampanyagenel);
			}
			
			YonetimAnasayfa();
		}
		else{
			printf("Ayn� �simde Bir Kampanya Bulunmaktad�r.\n[1] Kampanya Men�ye D�nmek i�in\n[2] Yeni bir kampanya olu�turmak i�in\nGiriniz: ");
			scanf("%d",&secim);
			if(secim==1){
				fclose(kampanyadosya);
				KampanyaAnaSayfa();
			}
			else if(secim==2){
				goto a;
			}
		}	
}


void KampanyaGoruntulemeMusteri(){
	FILE *kampanyagenel=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt","r");
	if(kampanyagenel==NULL){
		printf("Hen�z bir kampanya bulunmamaktad�r.\nAna Men�ye Y�nlendiriliyorsunuz...\n");
		fclose(kampanyagenel);
		sleep(1);
		MusteriAnasayfa();
	}
	else{
		while(fread(&kampanya,sizeof(kampanya),1,kampanyagenel)==1){
		
		printf("%s\n",kampanya.kampanyaadi);
		printf("%s\n\n",kampanya.kampanyabilgi);
		fclose(kampanyagenel);
		}
		printf("Ana Men�ye D�nmek i�in [1]\nGiriniz: ");
		scanf("%d",&secim);
		if(secim==1){
			AnaMenu();
		}
	}
	
	system("cls");
}

void KampanyaGoruntulemePersonel(){
	int i;
	FILE *kampanyaozel=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiOzel.txt","r");
	FILE *kampanyagenel=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt","r");
	if(kampanyaozel==NULL && kampanyagenel==NULL){
		printf("Hen�z bir kampanya bulunmamaktad�r.\nAna Men�ye Y�nlendiriliyorsunuz...\n");
		fclose(kampanyaozel);
		fclose(kampanyagenel);
		sleep(1);
		AnaMenu();
	}
	else{
		printf("PERSONELLERE A�T KAMPANYALAR: \n");
		for(i=0;i<50;i++){ printf("_");} printf("\n");
		while(fread(&kampanya,sizeof(kampanya),1,kampanyaozel)==1){
		
		printf("%s\n",kampanya.kampanyaadi);
		printf("%s\n\n",kampanya.kampanyabilgi);
		}
		printf("\n\n");
		printf("GENELE A�IK KAMPANYALAR: \n");
		for(i=0;i<50;i++){ printf("_");} printf("\n");
		while(fread(&kampanya,sizeof(kampanya),1,kampanyagenel)==1){
		printf("%s\n",kampanya.kampanyaadi);
		printf("%s\n\n",kampanya.kampanyabilgi);
		}
		fclose(kampanyagenel);
		fclose(kampanyaozel);
		printf("Ana Men�ye D�nmek i�in [1]\nGiriniz: ");
		scanf("%d",&secim);
		if(secim==1){
			AnaMenu();
		}
	}
	system("cls");
}

void KampanyaAnaSayfa(){
	int i;
	for(i=0;i<50;i++){ printf("_");} printf("\n");
	printf("\n     KAMPANYA SAYFASI\n");
	for(i=0;i<50;i++) {printf("_");} printf("\n");
	x:
	printf("[1] Kampanyalar� G�r�nt�lemek\n[2] Kampanya Kayd� Olu�turmak\n[3] Kampanya Silmek\n[5] Puan girmek\nGiriniz: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			KampanyaGoruntulemePersonel();
			break;
		case 2: 
			KampanyaEkle();
			break;
		case 3:
			KampanyaSil();
			break;
		case 4:
			puanGirdi();
			break;
		default: 
		printf("Yanl�� giri� yapt�n�z. Tekrar se�im yapmak i�in y�nlendiriliyorsunuz...\n");
		goto x;
	}
}


void indirkartSayfa()
{
	int i;
	int a=0;
	char kullaniciC[20];
	char kullaniciM[20];
	char kullaniciP[20];
	char dosyauzantisiM[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
	char dosyauzantisiP[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
    
    for(i=0;i<50;i++){ printf("_");} printf("\n");
	printf("\nAVM KART SAYFASINA HO� GELD�N�Z\n\n");
	
	printf("Kullan�c� ad�n�z� girerek g�ncel puan durumunuzu g�rebilirsiniz: ");
	scanf("%s",kullaniciC);
	printf("\n");
	
	strcpy(kullaniciM, kullaniciC);
	strcpy(kullaniciP, kullaniciC);
	
    strcat(kullaniciM,".txt");
    strcat(dosyauzantisiM,kullaniciM);
    strcat(kullaniciP,".txt");
    strcat(dosyauzantisiP,kullaniciP);
    
    FILE *dosya1=fopen(dosyauzantisiM,"r");
    FILE *dosya2=fopen(dosyauzantisiP,"r");
	if( dosya1 == NULL && dosya2 == NULL){
		printf("\tKayd�n�z yok veya silinmi�tir.\n");
		Sleep(3);
		fclose(dosya1);
		fclose(dosya2);
		system("cls");
		AnaMenu();
	}
	else if( dosya1 != NULL){
		fseek(dosya1,6*sizeof(cust),SEEK_SET);
		fread(&cust,sizeof(cust),1,dosya1);
		printf("\tMevcut ParaPuan�n�z: %.2f\n",cust.IndirimKarti.Puan);
		fclose(dosya1);
	}
	else if( dosya2 != NULL){
		fread(&per,sizeof(per),1,dosya2);
		fseek(dosya2,16*sizeof(per),SEEK_SET);
		printf("\tMevcut ParaPuan�n�z: %.2f\n",per.IndirimKarti.Puan);
		fclose(dosya2);
	}
	else{
		printf("\tHem m��teri hem personal kayd�n�z olamaz !");
		Sleep(3);
		system("cls");
		AnaMenu();
	}
	printf("\n");
	fclose(dosya1);
	fclose(dosya2);
	sleep(2);
	printf("not:\n");
	printf("Kayd� olmayan m��teri veya personelin puanlar� silinir.\n");
	printf("S�reye tabi puanlar kullan�lmad���nda silinir.\n");
	printf("Zaman� ge�mi� kampanyalardan puan al�namaz ve faydalan�lamaz.\n\n");
	sleep(4);
	AnaMenu();
}


void AnaMenu(){
	system("cls");
	system("color F3");
	int i;
    for(i=0;i<120;i++){printf("_");}printf("\n");
	printf("%45sHO� GELD�N�Z!\n","");
	for(i=0;i<120;i++){printf("_");}printf("\n");
	printf("M��TER� SAYFASI ���N [1]\t Y�NET�M SAYFASI ���N [2]\t PERSONEL SAYFASI ���N [3]\t YAYIN AKI�I [4]\n");
	for(i=0;i<120;i++){printf("_");}printf("\nGiriniz:");
	scanf("%d",&secim);
	switch(secim){
		case 1: 
			MusteriEkran();
			break;
		case 2: YonetimAnasayfa();
			break;
		case 3: PersonelEkran();
			break;
		case 4: yogunlukHesap();
			break;
		default:
			printf("Uygun De�er Girmediniz.\n Ana Men�ye Y�nlendiriliyorsunuz...\n");
			sleep(1);
			AnaMenu();
	}
}

void MusteriSayfa(){
	system("cls");
	int i,j;
    for(i=0;i<120;i++){printf("_");
    }
	printf("\n");
	for(i=0;i<120;i++){ printf("_");} printf("\n");
	printf(">|%78s%37s|<\n","    MARUN AVM M��TER� SAYFASI     ","");
    for(i=0;i<120;i++){printf("_");
	 }
    printf("\n");
	
	printf("M��TER�LER[1]\t M��TER� �ND�R�M KARTI B�LG� G�NCELLEME[2] ��KAYET �NER�LER[3]\tY�NET�M ANA SAYFA[4]\n");
	for(i=0;i<120;i++){ printf("_");} printf("\n");
	printf("\n��lem se�imi:");scanf("%d",&secim);
	switch(secim){
		case 1:
			MagazaMusterileri();
			break;
		case 2:
			indirkartSayfa();
			break;
		case 3:
            SikayetVeOneriGoster();
			break;
		case 4:
			YonetimAnasayfa();
			break;
		default:
			MusteriSayfa();
	}
}

void YonetimAnasayfa(){
	int i,j;
	int arasecim;
	char sifre[10];
	y:
		system("cls");
	system("color B0");
	for(j=0;j<2;j++){
		for(i=0;i<120;i++){printf("_");}
	   printf("\n");}
	printf("%48s   Y�NET�M SAYFASI\n","");
	for(j=0;j<2;j++){
	    for(i=0;i<120;i++){printf("_");}
	   	printf("\n");}
	printf("\nY�NET�C� G�R��� [1]\tY�NET�C� KAYDI [2]\tY�NET�C� KAYIT S�L [3]\tAVM ANA MEN� [4]\n");	
	for(i=0;i<120;i++){printf("_");}printf("\n");
	printf("��lem se�imi:");scanf("%d",&secim);
	switch(secim){
		case 1:
			x:
			printf("\nKullan�c� Ad�n�z� Giriniz: ");
			scanf("%s",yon.kullanici_adi);
			strcat(yon.kullanici_adi,".txt");
			char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Yonetim\\"; 
			strcat(dosyauzantisi,yon.kullanici_adi);
			FILE *yonetim = fopen(dosyauzantisi,"r");
			if(yonetim==NULL){
				printf("Kay�t Bulunamad�.\nTekrar denemek i�in [1]\nAna Men� i�in [2]\nGiriniz");
				scanf("%d",&secim);
				if(secim==1)goto x;
				else if(secim==2) goto y; 
			}
			else{
				printf("�ifre giriniz:");
				fflush(stdin);
				gets(sifre);
				while(fread(&yon,sizeof(yon),1,yonetim)==1){
					if(strcmp(sifre,yon.Sifre)==0){
						system("cls");
						for(i=0;i<120;i++){	printf("_");}
						printf("\nHO� GELD�N�Z!\n");
						for(i=0;i<120;i++){	printf("_");}
						printf("[1] M��teri ��lemleri\n[2] Personel ��lemleri\n[3] Ma�aza i�lemleri\n[4] AVM Yo�unluk g�r�nt�leme \n[5] Tatil G�nleri Giri�i\n[6] Kampanya i�lemleri \n[7] Kayd� Sil \n[8] AVM'nin Pandemi Uygunlu�u \n");
						for(i=0;i<120;i++){	printf("_");}
						printf("Giriniz: ");scanf("%d",&arasecim);
				        switch(arasecim){
					    case 1: MusteriSayfa();
					    break;
					    case 2: PersonelSayfa();
					    break;
					    case 3: 
						    printf("\n[1] Ma�aza Yap�land�rma ��lemleri\n[2] Ma�aza Bilgilerini G�sterme\n[3] Ma�aza Kay�tlanmas�\nGiriniz:");
						    scanf("%d",&arasecim);
						    if(arasecim==1)
							  MagazaYapilandirma();
						    else if(arasecim==2)
							   MagazayiGoster();
						    else if(arasecim==3)
						       MagazaKayit();
						break;
					    case 4: yogunlukHesap();
					    	break;
						case 5: tatiller();
					    	break;
					    case 6: KampanyaAnaSayfa();
					    	break;
						case 7: YonetimKayitSil();
					    	break;
					    case 8: MusteriSayisi();
					    	break;
				       }
					}
					else{
						printf("Kullan�c� ad� ve ya �ifre hatal�d�r...\n\n");
						goto x;
					}
				}	
			}
			break;
		case 2: YonetimKayit();
		break;
		case 3:YonetimKayitSil();
		break;
		case 4: AnaMenu();
		break;
		default:
			printf("Uygun De�er girmediniz.\n\n Ana Men�ye Y�nlendiriliyorsunuz...\n");
			sleep(1);
			YonetimAnasayfa();
			break;
	}
}

void YonetimKayit(){
	int i;
	system("cls");
	printf("               Y�NET�C� KAYIT EKRANI\n");
	for(i=0;i<50;i++){ printf("_");}
    printf("\n");
	char sifre[10];
	a:
    printf("KULLANICI ADI G�R�N�Z : ");
    scanf("%s",yon.kullanici_adi);
    strcat(yon.kullanici_adi,".txt");
    char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Yonetim\\";
    strcat(dosyauzantisi,yon.kullanici_adi);
	FILE *yonetimd=fopen(dosyauzantisi,"r");
	    if(yonetimd==NULL){
	    	fclose(yonetimd);
		     FILE *yonetimd=fopen(dosyauzantisi,"w+");
	    	do{
				printf("��FRE G�R�N�Z (�ifre 6-10 karakter aras� olmal�d�r) : ");
				scanf("%s",&sifre);
				}while(strlen(sifre)<6);
			k:
				printf("��FREY� TEKRAR G�R�N�Z(ilk girilen �ifre ile ayn� olmal�d�r) : ");
				scanf("%s",yon.Sifre);
				if(strcmp(sifre,yon.Sifre)!=0){
						goto k;
				}
         fflush(stdin);
    	 printf("ADI SOYADI : ");
	     fflush(stdin);
	     gets(yon.adsoyad);
	     printf("TC K�ML�K NO : ");
	     scanf("%s",yon.TCKimlik);
	     printf("C�NS�YET : ");
	     scanf("%s",yon.cinsiyet);
	     printf("YA� : ");
	     scanf("%d",&yon.yas);
	     printf("MAA� : ");
	     scanf("%f",&yon.maas);
	     printf("DO�RULAMA SORUSU (�rn.Anne k�zl�k soyad� ilk ve son hanesi) ? : ");
	     scanf("%s",yon.Dogrulama);
	     printf("E-POSTA ADRES� : ");
	     scanf("%s",yon.Iletisim.E_Posta);
	     printf("DO�UM G�N� (gg/aa/yyyy) : ");
	     scanf("%s",yon.DogumGunu);
	     fwrite(&yon,sizeof(yon),1,yonetimd);
	     fclose(yonetimd);  
	}
	else{
	     printf("Bu kullan�c� ad� kullan�lmaktad�r. Tekrar deneyiniz\n");
	     goto a;
	}
	fclose(yonetimd);
	printf("Kayd�n�z ba�ar�yla ger�ekle�tirilmi�tir.\n");
	YonetimAnasayfa();	
}
void YonetimKayitSil(){
	int a=0;
	char kullanici[20],sifre[10];
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Yonetim\\";
    	printf("KULLANICI ADI G�R�N�Z:");
    	scanf("%s",kullanici);
    	strcat(kullanici,".txt");
    	strcat(dosyauzantisi,kullanici);
    	FILE *yonetimd=fopen(dosyauzantisi,"r");
	 if(yonetimd==NULL){
	 	printf("KAYIT BULUNMAMAKTADIR.");
	 }
	 else{
	 	printf("��FRE G�R�N�Z:");
		 scanf("%s",sifre);
	 	while(fread(&yon,sizeof(yon),1,yonetimd)==1){
	 		if(strcmp(sifre,yon.Sifre)==0){
	 			a=1;
			 }
	     }
	  }
	  if(a==0){
		printf("Kullan�c� ad� ya da �ifre hatal�.\nKay�t Bulunamad�.");
	     }
	 else {
		printf("�lgili hesap kay�tlardan silinmi�tir.");
		fclose(yonetimd);
		remove(dosyauzantisi);
	    }
	  fclose(yonetimd);
	  sleep(2);
	  YonetimAnasayfa();
}


void MusteriEkran(){
	system("cls");
	system("color 74");
	int i,j;
	char ara[12];
	
	for(j=0;j<2;j++){
	    for(i=0;i<120;i++){printf("_");}
	   printf("\n");}
	printf("%70s%38s\n","MARUN AVM  M��TER�  ","");
	for(j=0;j<2;j++){
		for(i=0;i<120;i++){printf("_");}
		printf("\n");}
	
	printf("%80s\n","[1]�YE OL\t[2]G�R�� YAP\t[3]��FREM� UNUTTUM\t[4]KAYIT S�L\t[5]AVM SAYFASI");
	for(i=0;i<120;i++){printf("_");}
	printf("\nSE�:");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			MusteriKayit();
		    break;
		case 2:
			MusteriGiris();
		    break;
		case 3:
			SifremiUnuttum();
			break;
		case 4:
			MusteriKayitSil();
			break;
		case 5:
		    AnaMenu();
		    break;
		default:
			printf("Uygun deger giriniz! \n");
			MusteriEkran();
	}
}

void MusteriGiris(){
	int i;
	system("cls");
	printf("                 G�R�� YAP\n");
	for(i=0;i<50;i++){printf("_");}
	printf("\n");
	char kullaniciadi2[20],sifre2[10];
	printf("kullan�c� ad�:");
	fflush(stdin);
	gets(kullaniciadi2);
	printf("�ifre");
	fflush(stdin);
	gets(sifre2);
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
    strcat(kullaniciadi2,".txt");
    strcat(dosyauzantisi,kullaniciadi2);
	FILE *dd=fopen(dosyauzantisi,"r");
	if(dd==NULL)
	{
		printf("Dosya bulunamadi - Herhangi bir kayit yok");
		sleep(2);
		MusteriEkran();
	}
	else
	{
		while(fread(&cust,sizeof(cust),1,dd)==1)
		{
			if(strcmp(sifre2,cust.Sifre)==0)
			{
				printf("Giris Basarili ");
				sleep(2);
				MusteriAnasayfa();
			}
			else{
				printf("Giris Basarisiz ");
				fclose(dd);
			    sleep(1);
			    MusteriEkran();
			}
		}
	}
	
}
void SifremiUnuttum(){
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
	char  kullanici[10],alternatif[20];
	printf("KULLANICI ADI G�R�N�Z:");
    scanf("%s",kullanici);
    strcat(kullanici,".txt");
    strcat(dosyauzantisi,kullanici);
	FILE *dd=fopen(dosyauzantisi,"r");
	int k=0; 
	if(dd!=NULL){	
		  printf("Do�rulama sorusu cevab�:");scanf("%s",&alternatif);
		  while(fread(&cust,sizeof(cust),1,dd)==1){
	        if(strcmp(alternatif,cust.Dogrulama)==0){
	        k=1;
	      	printf("��FREN�Z: %s\n",cust.Sifre);
	      	sleep(1);
		  } 
		}
    } 
	if(k==0){
		printf("B�yle bir kay�t bulunmamaktad�r.Kullan�c� ad� ya da �ifre giri�i hatal� olabilir.\n");
		sleep(1);
	}    		
	else if(dd==NULL){
		printf("...Dosya bulunamad�...");
		sleep(1);
	}
	fclose(dd);
	MusteriEkran();
}
void MusteriKayitSil(){
	int a=0;
	char kullanici[20],sifre[10];
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
    printf("KULLANICI ADI G�R�N�Z:");
    scanf("%s",kullanici);
    strcat(kullanici,".txt");
    strcat(dosyauzantisi,kullanici);
    FILE *dd=fopen(dosyauzantisi,"r");
    FILE *must=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\m��teriler.txt","r");
    FILE *temp=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\ge�ici.txt","a");
	 if(dd==NULL||must==NULL){
	 	printf("KAYIT BULUNMAMAKTADIR.");
	 }
	 else{
	 	printf("��FRE G�R�N�Z:");scanf("%s",sifre);
	 	while(fread(&cust,sizeof(cust),1,dd)==1){
	 		if(strcmp(sifre,cust.Sifre)==0){
	 			a=1;
			 }
			 while(fread(&cust,sizeof(cust),1,must)==1){
	     	    if(strcmp(kullanici,cust.kullanici_adi)!=0){
	     	    	fwrite(&cust,sizeof(cust),1,temp);
	     	    	
				 }
		     }
	     }
	  }
	  if(a==0){
		printf("Kullan�c� ad� ya da �ifre hatal�.\nB�yle Bir M��teri Kay�tlarda Bulunamad�.");
	     }
	 else {
		printf("�lgili hesap kay�tlardan silinmi�tir.");
		fclose(dd);
		fclose(must);
		fclose(temp);
		remove(dosyauzantisi);
	    remove("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\m��teriler.txt");
	    rename("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\ge�ici.txt","C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\m��teriler.txt");
	    }
	  fclose(dd);
	  sleep(2);
	  MusteriEkran();
}
void MusteriAnasayfa(){
	system("cls");
	int i,j;
	char ara[12];
	
	for(j=0;j<2;j++){
	    for(i=0;i<100;i++){printf("_");
	   }
	   printf("\n");
	}
	printf("_%60s%38s_\n","   MARUN AVM M��TER� ANASAYFASINA HO�GELD�N�Z     ","");for(j=0;j<2;j++){
	    for(i=0;i<100;i++){printf("_");
	   }
	   printf("\n");
	}
	printf("M��TER� B�LG�LER�[1]%78s\n�ND�R�M KARTI ��LEMLER�[2]%72s\n��KAYET VE �NER�LER[3]%76s\nKAMPANYALAR[4]%76s\n�IKI�[5]%90s\n","","","","","");
	for(i=0;i<100;i++){printf("_");
	   }
    printf("\n");
    printf("��lem Se�imi:");scanf("%d",&secim);
    system("cls");
    switch(secim){
    	case 1:
    		printf("TC NO:");scanf("%s",ara);
    	    MusteriBilgileri(ara);
    		break;
    	case 2:
            indirkartSayfa();
    		break;
    	case 3:
    		SikayetVeOneri();
    		break;
    	case 4:
    		KampanyaGoruntulemeMusteri();
    		break;
    	case 5:
    		printf("�IKI� YAPMI� BULUNMAKTASINIZ...");
    		MusteriEkran();
    		break;
    	default:
    		printf("L�tfen uygun bir i�lem numaras� se�iniz..");
    		MusteriAnasayfa();
	}
}
void MusteriKayit(){
	int i;
	system("cls");
	printf("               MUSTER� KAYIT EKRANI\n");
	for(i=0;i<50;i++){ printf("_");}
    printf("\n");
	char sifre[10];
	a:
    printf("KULLANICI ADI G�R�N�Z:");
    scanf("%s",cust.kullanici_adi);
    strcat(cust.kullanici_adi,".txt");
    char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
    strcat(dosyauzantisi,cust.kullanici_adi);
	FILE *dd=fopen(dosyauzantisi,"r");
	    if(dd==NULL){
	    	fclose(dd);
		     FILE *ff=fopen(dosyauzantisi,"a+");
		     FILE *must=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\m��teriler.txt","a+");
		     fwrite(&cust,sizeof(cust),1,must);
		     fclose(must);
	    	do{
					printf("��FRE G�R�N�Z (�ifre 6-10 karakter aras� olmal�d�r):");
					scanf("%s",&sifre);
				}while(strlen(sifre)<6);
			k:
				printf("��FREY� TEKRAR G�R�N�Z(ilk girilen �ifre ile ayn� olmal�d�r):");
				scanf("%s",cust.Sifre);
				if(strcmp(sifre,cust.Sifre)!=0){
						goto k;
				}
         fflush(stdin);
	     printf("��FREN�Z:");
    	 puts(cust.Sifre);
	     printf("M��TER� K�ML�K NUMARASI:");
	     scanf("%s",cust.KimlikNo);
	     printf("M��TER� ADI:");
	     scanf("%s",cust.Ad);
	     printf("M��TER� SOYADI:");
	     scanf("%s",cust.Soyad);
	     printf("DO�RULAMA SORUSU(�rn.Anne k�zl�k soyad� ilk ve son hanesi) ?:");
	     scanf("%s",cust.Dogrulama);
	     printf("M��TER� DO�UM G�N� (gg/aa/yyyy):");
	     scanf("%s",cust.DogumGunu);
	     printf("TELEFON:");
	     scanf("%s",cust.Iletisim.Telefon);
	     printf("E-POSTA ADRES�:");
	     scanf("%s",cust.Iletisim.E_Posta);
	     fwrite(&cust,sizeof(cust),1,ff);
	     fclose(ff);
	}
	else{
	     printf("Bu kullan�c� ad� kullan�lmaktad�r. Tekrar deneyiniz\n");
	     goto a;
	}
	fclose(dd);	
	MusteriEkran();
}

void MusteriBilgileri(char ARA[]){
	int i;
	char kullanici2[20];
	for(i=0;i<100;i++){printf("_");}
	printf("\n");
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
	printf("KULLANICI ADI G�R�N�Z:");
    scanf("%s",kullanici2);
    strcat(kullanici2,".txt");
    strcat(dosyauzantisi,kullanici2);
	FILE *dd=fopen(dosyauzantisi,"r");
	if(dd != NULL){
		    while(fread(&cust,sizeof(cust),1,dd)==1){
		    	if(strcmp(ARA,cust.KimlikNo)==0){
				    do{
	                 printf("M��TER� TC K�ML�K NO:%s\n",cust.KimlikNo);
                     printf("M��TER� ADI:%s \n",cust.Ad);
                     printf("M��TER� SOYADI:%s\n",cust.Soyad);
	                 printf("M��TER� DO�UM G�N�:%s \n",cust.DogumGunu);
	                 printf("M��TER� TELEFON:%s\n",cust.Iletisim.Telefon);
	                 printf("M��TER� E-POSTA:%s\n",cust.Iletisim.E_Posta);
	                 for(i=0;i<100;i++){printf("_");}
	                 printf("\nAnasayfa i�in 1(bir)i giriniz:");
	                 scanf("%d",&secim);
					}while(secim!=1);
					MusteriAnasayfa();
				 }
	             else{
	             	printf("KAYIT BULUNAMADI\n");
	             	sleep(1);
	             	MusteriAnasayfa();
				 }
			}
		fclose(dd);
		secim=0;
		MusteriAnasayfa();
	}
	else{
		printf("Kay�t yok\n");
		sleep(1);
		MusteriAnasayfa();
	}
}

void MagazaMusterileri(){
	system("cls");
	int i;
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
    FILE *must=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\m��teriler.txt","r");
	printf("%60sT�M M��TER�LER(M��teri dosyalar�)\n","");
	for(i=0;i<120;i++){printf("_");}printf("\n");
	while(fread(&cust,sizeof(cust),1,must)==1){
		printf("%s\n",cust.kullanici_adi);
	}
	for(i=0;i<120;i++){printf("_");}printf("\n");
	fclose(must);
	y:
	printf("M��TER�LERDE ARA[1]\t M��TER� SAYFASINA G�T[2]\n Se�im:");
	scanf("%d",&secim);
	switch(secim){
		case 1:
				printf("KULLANICI ADI G�R�N�Z:"); 
                scanf("%s",cust.kullanici_adi);
                strcat(cust.kullanici_adi,".txt");
                strcat(dosyauzantisi,cust.kullanici_adi);
	            FILE *dd=fopen(dosyauzantisi,"r");
                if(dd==NULL){
    	             printf("DOSYA BULUNMAMAKTADIR.KAYIT OLU�TURUNUZ!");
            	}
	            else{
		             if(fread(&cust,sizeof (cust),1,dd)==1){
		                 printf("\nM��TER� DOSYASI:%s",cust.kullanici_adi);
	                     printf("\nM��TER� TC K�ML�K NO:%s",cust.KimlikNo);
                         printf("\nM��TER� ADI-SOYADI:%s %s",cust.Ad,cust.Soyad);
	                     printf("\nM��TER� DO�UM G�N�:%s",cust.DogumGunu);
	                     printf("\nM��TER� TELEFON:%s",cust.Iletisim.Telefon);
	                     printf("\nM��TER� E-POSTA:%s",cust.Iletisim.E_Posta);
	                }   
	                 else{
	    	             printf("b�yle bir m��teri bulunmamaktad�r.\n");
		            }
	             }
                 do{
		         printf("\nM��TER� SAYFA ���N 1(B�R)'� TU�LAYINIZ:");scanf("%d",&secim);
	             }while(secim!=1);
	             fclose(dd);  
	             MusteriSayfa();
	             break;
	     case 2:
		     MusteriSayfa();
			 break;
		 default:
		     printf("uygun bir de�er giriniz.\n");
		     goto y;   
	}	
}
void SikayetVeOneriGoster(){
	char gec;
	int i;
	system("cls");
	printf("\n     ��KAYET VE �NER� B�LD�R�LER�\n");
	for(i=0;i<50;i++){ printf("_");} printf("\n");
    printf("[1]��KAYET\n[2]�NER�LER\n");
    printf("g�r�nt�lemek istedi�iniz se�ene�i se�iniz:");scanf("%d",&secim);
	char dosyauzantisi1[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\sikayet.txt";
	FILE *sikayet=fopen(dosyauzantisi1,"r");
	char dosyauzantisi2[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\oneri.txt";
	FILE *oneri=fopen(dosyauzantisi2,"r");
    switch(secim){
		case 1:
			printf("��KAYETLER\n");
			for(i=0;i<50;i++){printf("_");}printf("\n");
			while(fread(&cust,sizeof(cust),1,sikayet)==1){
			printf("%s\t",cust.kullanici_adi);
		    printf("%s\n",cust.SikayetveOneri.Sikayet);}
		    secim=0;
		    printf("\nGeri D�nmek i�in bir tu�a bas�n.\n");
		    gec=getch();
			MusteriSayfa();	
		    break;
		case 2:
			printf("�NER�LER\n");
			for(i=0;i<50;i++){printf("_");}printf("\n");
			while(fread(&cust,sizeof(cust),1,oneri)==1){
			printf("%s\t",cust.kullanici_adi);
			printf("%s\n",cust.SikayetveOneri.Oneri);}
			secim=0;
			printf("\nGeri D�nmek i�in bir tu�a bas�n.\n");
		    gec=getch();
			MusteriSayfa();
			break;
	}
	fclose(sikayet);
	fclose(oneri);
}
void SikayetVeOneri(){
	system("cls");
	int i;
	printf("\n     ��KAYET VE �NER�LER\n");
	for(i=0;i<50;i++){ printf("_");} printf("\n");
    char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
	printf("[1]��KAYET\n[2]�NER�LER\n");
	printf("��lem se�imi:");scanf("%d",&secim);
	switch (secim){
		case 1:
			strcat(dosyauzantisi,"sikayet.txt");
			FILE *sikayet=fopen(dosyauzantisi,"a+");
		    fflush(stdin);
			printf("Ma�azam�zla ilgili �ikayetinizi belirtiniz:");
			gets(cust.SikayetveOneri.Sikayet);
			fwrite(&cust,sizeof(cust),1,sikayet) ;
			fclose(sikayet);
			printf("�ikayetiniz iletilmi�tir.�yi g�nler dileriz.\n");
			sleep(3);
			MusteriAnasayfa();
			break;
		case 2:
			strcat(dosyauzantisi,"oneri.txt");
			FILE *oneri=fopen(dosyauzantisi,"a+");
		    fflush(stdin);
			printf("Daha  iyi bir hizmet i�in �nerileriniz...\n");
			gets(cust.SikayetveOneri.Oneri);
			fwrite(&cust,sizeof(cust),1,oneri);
			fclose(oneri);
			printf("�neriniz iletilmi�tir.�yi g�nler dileriz...\n");
			sleep(3);
			MusteriAnasayfa();
			break;
		default:
			printf("Uygun  bir tercih giriniz...\n");
			MusteriAnasayfa();
	}
}

void PersonelSayfa(){
	system("cls");
	int i,j;
    for(i=0;i<100;i++){printf("_");
    }
	printf("\n");
	
	printf(">|%59s%37s|<\n","    MARUN AVM PERSONEL SAYFASI     ","");
    for(i=0;i<100;i++){printf("_");
	 }
    printf("\n");
	
	printf("PERSONELLER[1]\t PERSONEL �ND�R�M KARTI G�R�NT�LEME[2] ��KAYET �NER�LER[3]\tY�NET�M ANA SAYFA[4]\n");
	printf("\n��lem se�imi:");scanf("%d",&secim);
	switch(secim){
		case 1:
			MagazaPersonelleri();
			break;
		case 2:
			indirkartSayfa();
			break;
		case 3:
            SikayetVeOneriGoster2();
			break;
		case 4:
			YonetimAnasayfa();
			break;
		default:
			PersonelSayfa();
	}
}
void PersonelEkran(){
	system("cls");
	system("color E5");
	int i,j;
	char ara[12];
	
	for(j=0;j<2;j++){
	    for(i=0;i<120;i++){printf("_");
	   }
	   printf("\n");
	}
	printf("%70s%38s\n","   MARUN AVM PERSONEL  ","");for(j=0;j<2;j++){
	    for(i=0;i<120;i++){printf("_");
	   }
	   printf("\n");
	}
	
	printf("%80s","[1]�YE OL\t[2]G�R�� YAP\t[3]��FREM� UNUTTUM\t[4]KAYIT S�L\t[5]AVM SAYFASI\n","");
	for(i=0;i<120;i++){printf("_");
	   }printf("\nSE��M:");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			PersonelKayit();
		    break;
		case 2:
			PersonelGiris();
		    break;
		case 3:
			SifremiUnuttum2();
			break;
		case 4:
			PersonelKayitSil();
			break;
		case 5:
		    AnaMenu();
		    break;
		default:
			printf("Uygun deger giriniz! \n");
			PersonelEkran();
	}
}

void PersonelGiris(){
    int i;
	system("cls");
	printf("                 G�R�� YAP\n");
	for(i=0;i<50;i++){printf("_");}
	printf("\n");
	char kullaniciadi2[20],sifre2[10];
	printf("Kullan�c� ad� : ");
	fflush(stdin);
	gets(kullaniciadi2);
	printf("�ifre : ");
	fflush(stdin);
	gets(sifre2);
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
    strcat(kullaniciadi2,".txt");
    strcat(dosyauzantisi,kullaniciadi2);
	FILE *dosya=fopen(dosyauzantisi,"r");
	if(dosya==NULL)
	{
		printf("Dosya bulunamadi\nHerhangi bir kayit yok");
		sleep(1);
		PersonelEkran();
	}
	else
	{
		while(fread(&per,sizeof(per),1,dosya)==1)
		{
			if(strcmp(sifre2,per.Sifre)==0)
			{
				printf("Giri� Ba�ar�l�.\n");
				sleep(1);
				PersonelAnasayfa();
			}
			else{
				printf("Giri� Ba�ar�s�z.\nTekrar giri� i�in y�nlendiriliyorsunuz...\n");
				fclose(dosya);
			    sleep(2);
			    PersonelEkran();
			}
		}
	}
	
}
void SifremiUnuttum2(){
	int i;
	system("cls");
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
	char  kullanici[10],alternatif[20];
	printf("\n         ��FREM� G�R�NT�LE\n");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("KULLANICI ADI G�R�N�Z:");
    scanf("%s",kullanici);
    strcat(kullanici,".txt");
    strcat(dosyauzantisi,kullanici);
	FILE *dosya=fopen(dosyauzantisi,"r");
	int k=0; 
	if(dosya!=NULL){	
		  printf("Do�rulama sorusu cevab�:");
		  scanf("%s",&alternatif);
		  while(fread(&per,sizeof(per),1,dosya)==1){
	        if(strcmp(alternatif,per.Dogrulama)==0){
	        k=1;
	      	printf("��FREN�Z: %s\n",per.Sifre);
	      	sleep(1);
		  } 
		}
    } 
	if(k==0){
		printf("B�yle bir kay�t bulunmamaktad�r.\nKullan�c� ad� ya da �ifre giri�i hatal� olabilir.\n");
		sleep(2);
	}    		
	else if(dosya==NULL){
		printf("Dosya bulunamad�.\nPersonel ekran�na y�nlendiriliyorsunuz...\n");
		sleep(2);
	}
	fclose(dosya);
	PersonelEkran();
}
void PersonelKayitSil(){
	int a=0;
	int i;
	system("cls");
	char kullanici[20],sifre[10];
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("        PERSONEL KAYIT S�LME EKRANI\n");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	
    printf("KULLANICI ADI G�R�N�Z:");
    scanf("%s",kullanici);
    strcat(kullanici,".txt");
    strcat(dosyauzantisi,kullanici);
    FILE *dosya=fopen(dosyauzantisi,"r");
    FILE *person=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\calisanlar.txt","r");
    FILE *gecici=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\gecicii.txt","a");
	 if(dosya==NULL||gecici==NULL){
	 	printf("KAYIT BULUNMAMAKTADIR.");
	 }
	 else{
	 	printf("��FRE G�R�N�Z:");scanf("%s",sifre);
	 	while(fread(&per,sizeof(per),1,dosya)==1){
	 		if(strcmp(sifre,per.Sifre)==0){
	 			a=1;
			 }
			 while(fread(&per,sizeof(per),1,person)==1){
	     	    if(strcmp(kullanici,per.kullanici_adi)!=0){
	     	    	fwrite(&per,sizeof(per),1,gecici);	
				 }
		     }
	     }
	  }
	  if(a==0){
		printf("Kullan�c� ad� ya da �ifre hatal�.\nB�yle Bir Personel Kay�tlarda Bulunamad�.");
	     }
	 else {
		printf("�lgili hesap kay�tlardan silinmi�tir.");
		fclose(dosya);
		fclose(person);
		fclose(gecici);
		remove(dosyauzantisi);
	    remove("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\calisanlar.txt");
	    rename("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\gecicii.txt","C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\calisanlar.txt");
	    }
	  fclose(dosya);
	  sleep(2);
	 PersonelEkran();
}
void PersonelAnasayfa(){
	system("cls");
	int i,j;
	char ara[12];
	
	for(j=0;j<2;j++){
	    for(i=0;i<100;i++){printf("_");
	   }
	   printf("\n");
	}
	printf("_%60s_","   MARUN AVM PERSONEL ANASAYFASINA HO�GELD�N�Z     ","");for(j=0;j<2;j++){
	    for(i=0;i<100;i++){printf("_");
	   }
	   printf("\n");
	}
	printf("PERSONEL B�LG�LER�[1]%78s\nPERSONEL �Z�N G�NLER�[2]%72s\n�ND�R�M KARTI ��LEMLER�[3]%72s\n��KAYET VE �NER�LER[4]%76s\nKAMPANYALAR [5]%72s\n�IKI�[6]%90s\n","","","","","");
	for(i=0;i<100;i++){printf("_");
	   }
    printf("\n");
    printf("��lem Se�imi:");
	scanf("%d",&secim);
    system("cls");
    switch(secim){
    	case 1:
    		printf("Aranacak personele ait TC No:");
			scanf("%s",ara);
    	    PersonelBilgileri(ara);
    		break;
    	case 2:
    		izingunleri();
    		break;
    	case 3:
    		indirkartSayfa();
    		break;
    	case 4:
    		SikayetVeOneri2();
    		break;
    	case 5:
    		KampanyaGoruntulemePersonel();
    		break;
    	case 6:
    		printf("�IKI� YAPILMI�TIR");
    		PersonelEkran();
    		break;
    	default:
    		printf("L�tfen uygun bir i�lem numaras� se�iniz..");
    		PersonelAnasayfa();
	}
}
void PersonelKayit(){
	int i;
	system("cls");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("               PERSONEL KAYIT EKRANI\n");
	for(i=0;i<50;i++){ printf("_");}
    printf("\n");
	char sifre[10];
	b:
	printf("PERSONEL�N �ALI�TI�I MA�AZA K�ML���: ");
	scanf("%s",Boyut.Magazakimlik);
    strcat(Boyut.Magazakimlik,".txt");
  	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\";
    strcat(dosyauzantisi,Boyut.Magazakimlik);	
	FILE *magaza =fopen(dosyauzantisi,"r");
	if(magaza==NULL){
		printf("Ma�aza Kimli�i Yanl��t�r.\n");
		fclose(magaza);
		goto b;
	}
	else{
		magaza=fopen(dosyauzantisi,"a");

	a:
    printf("KULLANICI ADI G�R�N�Z : ");
    scanf("%s",per.kullanici_adi);
    strcat(per.kullanici_adi,".txt");
    char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
    strcat(dosyauzantisi,per.kullanici_adi);
	FILE *dosya=fopen(dosyauzantisi,"r");
	    if(dosya==NULL){
	    	fclose(dosya);
		     FILE *fdosya=fopen(dosyauzantisi,"a+");
		     FILE *person=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\calisanlar.txt","a+");
	         fwrite(&per,sizeof(per),1,person);
		     fclose(person);
	    	do{
					printf("��FRE G�R�N�Z (�ifre 6-10 karakter aras� olmal�d�r) : ");
					scanf("%s",&sifre);
				}while(strlen(sifre)<6);
			k:
				printf("��FREY� TEKRAR G�R�N�Z(ilk girilen �ifre ile ayn� olmal�d�r) : ");
				scanf("%s",per.Sifre);
				if(strcmp(sifre,per.Sifre)!=0){
						goto k;
				}
         fflush(stdin);
    	 printf("PERSONEL ADI SOYADI : ");
	     fflush(stdin);
	     gets(per.adsoyad);
	     printf("PERSONEL TC K�ML�K NO : ");
	     scanf("%s",per.TCKimlik);
	     printf("C�NS�YET : ");
	     scanf("%s",per.cinsiyet);
	     printf("YA� : ");
	     scanf("%d",&per.yas);
	     Boyut.Magazaper=per.adsoyad;
		 fwrite(&Boyut,sizeof(Boyut),1,magaza);
		 fclose(magaza);
	     printf("PERSONEL MAA� : ");
	     scanf("%f",&per.maas);
	     printf("DO�RULAMA SORUSU (�rn.Anne k�zl�k soyad� ilk ve son hanesi) ? : ");
	     scanf("%s",per.Dogrulama);
	     printf("E-POSTA ADRES� : ");
	     scanf("%s",per.Iletisim.E_Posta);
	     printf("PERSONEL DO�UM G�N� (gg/aa/yyyy) : ");
	     scanf("%s",per.DogumGunu);
	     fwrite(&per,sizeof(per),1,fdosya);
	     fclose(fdosya);  
	}
	else{
	     printf("Bu kullan�c� ad� kullan�lmaktad�r. Tekrar deneyiniz\n");
	     sleep(2);
	     goto a;
	}
	fclose(dosya);	
	sleep(2);
	PersonelEkran();}
}
void PersonelBilgileri(char ARA[]){
	int i;
	system("cls");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("          PERSONEL B�LG�S�\n");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	char kullanici2[20];
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
	printf("KULLANICI ADI G�R�N�Z:");
    scanf("%s",kullanici2);
    for(i=0;i<100;i++){printf("_");}
    printf("\n");
    strcat(kullanici2,".txt");
    strcat(dosyauzantisi,kullanici2);
	FILE *dosya=fopen(dosyauzantisi,"r");
	if(dosya != NULL){
		    while(fread(&per,sizeof(per),1,dosya)==1){
		    	if(strcmp(ARA,per.TCKimlik)==0){
				    do{
				    	printf("PERSONEL ADI SOYADI : %s\n",per.adsoyad);
	     				printf("PERSONEL TC K�ML�K NO : %s\n",per.TCKimlik);
	     				printf("C�NS�YET : %s\n",per.cinsiyet);
	     				printf("YA� : %d\n",per.yas);
	    				printf("PERSONEL MAA� : %.2f TL\n",per.maas);
	    				printf("DO�RULAMA SORUSU CEVABI : %s\n",per.Dogrulama);
	    				printf("E-POSTA ADRES� : %s\n",per.Iletisim.E_Posta);
	     				printf("PERSONEL DO�UM G�N� (gg/aa/yyyy) : %s\n",per.DogumGunu);
	     				printf("\n�Z�NL� OLDU�U G�NLER:\n");
	     				if(per.tatil.tatilsayisi>0){
	     				for(i=0;i<per.tatil.tatilsayisi;i++){
							printf("%d.0%d.%d  \n",per.tatil.tatiller[i][0],per.tatil.tatiller[i][1],per.tatil.tatiller[i][2]);}}
						else{
							printf("Personel �zin G�nlerini Kullanmam��t�r.\n");
						}
	                 for(i=0;i<100;i++){printf("_");}
	                 printf("\nAnasayfa i�in 1(bir)i giriniz:");
	                 scanf("%d",&secim);
					}while(secim!=1);
					fclose(dosya);
					PersonelAnasayfa();
				 }
	             else{
	             	printf("KAYIT BULUNAMADI\n");
	             	sleep(1);
	             	PersonelAnasayfa();
				 }
			}
		fclose(dosya);
		secim=0;
		PersonelAnasayfa();
	}
	else{
		printf("Kay�t yok\n");
		sleep(1);
		PersonelAnasayfa();
	}
}
void izingunleri(){
	system("cls");
	int i;
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("            PERSONEL �Z�N G�R���\n");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("KULLANICI ADI G�R�N�Z:"); 
    scanf("%s",per.kullanici_adi);
    strcat(per.kullanici_adi,".txt");
    strcat(dosyauzantisi,per.kullanici_adi);
	FILE *dosya=fopen(dosyauzantisi,"r");
    if(dosya==NULL){
    	printf("KULLANICI BULUNMAMAKTADIR.KAYIT OLU�TURUNUZ!");
    	sleep(1);
    	PersonelEkran();
	}
	else{
		fclose(dosya);
		FILE *fdosya=fopen(dosyauzantisi,"w");
			int i;
			printf("\n �Z�N G�NLER�\n____________________________\n");
			x:
			printf("Ka� izin g�n� kullanaca��n�z� giriniz: ");
			scanf("%d",&per.tatil.tatilsayisi);
		if(per.tatil.tatilsayisi>30){
			printf("30 G�nden fazla �zin kullan�lamaz.\nTekrar y�nlendiriliyorsunuz.\n\n\n");
			goto x;
		}
		else{
		
			per.tatil.tatiller[per.tatil.tatilsayisi][3];
		
		for(i=0;i<per.tatil.tatilsayisi;i++){
		printf("%d. �zin Giri�i:\n",i+1);
		printf("G�n�n� girin: ");
		scanf("%d",&per.tatil.tatiller[i][0]);
		printf("Ay�n� girin: ");
		scanf("%d",&per.tatil.tatiller[i][1]);
		printf("Y�l�n� girin: ");
		scanf("%d",&per.tatil.tatiller[i][2]);
		printf("\n");}
	
	printf("Se�ilmi� Olan �zin G�nleri\n");
	for(i=0;i<per.tatil.tatilsayisi;i++){
		printf("%d.0%d.%d  \n",per.tatil.tatiller[i][0],per.tatil.tatiller[i][1],per.tatil.tatiller[i][2]);} //gun.ay.yil
	printf("\n\n");	
	fflush(stdin);
	fwrite(&per,sizeof(per),1,dosya);
	fclose(dosya);
	printf("Personel ekran�na Y�nlendiriliyorsunuz...\n\n");
	sleep(2);
	PersonelAnasayfa();
	}
	}
}

void MagazaPersonelleri(){
	system("cls");
	int i;
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
    FILE *person=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\calisanlar.txt","r");
    for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("    T�M PERSONELLER(Personel dosyalar�)   \n");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	while(fread(&per,sizeof(per),1,person)==1){
		printf("%s\n",per.kullanici_adi);
	}
	fclose(person);
	y:
	printf("PERSONELLERDE ARA[1]\t PERSONEL SAYFASINA G�T[2]\n Se�im:");
	scanf("%d",&secim);
	switch(secim){
		case 1:
				printf("KULLANICI ADI G�R�N�Z:"); 
                scanf("%s",per.kullanici_adi);
                strcat(per.kullanici_adi,".txt");
                strcat(dosyauzantisi,per.kullanici_adi);
	            FILE *dosya=fopen(dosyauzantisi,"r");
                if(dosya==NULL){
    	             printf("DOSYA BULUNMAMAKTADIR.KAYIT OLU�TURUNUZ!");
            	}
	            else{
		             if(fread(&per,sizeof (per),1,dosya)==1){
		             	printf("PERSONEL ADI SOYADI : %s\n",per.adsoyad);
						printf("PERSONEL TC K�ML�K NO : %s\n",per.TCKimlik);
						printf("C�NS�YET : %s\n",per.cinsiyet);
	  					printf("YA� : %d\n",per.yas);
	  					printf("�ALI�TI�I MA�AZA : %s\n",per.calistigiMagaza);
	    				printf("PERSONEL MAA� : %.2f TL\n",per.maas);
	    				printf("DO�RULAMA SORUSU CEVABI : %s\n",per.Dogrulama);
	    				printf("E-POSTA ADRES� : %s\n",per.Iletisim.E_Posta);
	     				printf("PERSONEL DO�UM G�N� (gg/aa/yyyy) : %s\n",per.DogumGunu);
	     				printf("\n�Z�NL� OLDU�U G�NLER:\n");
	     				if(per.tatil.tatilsayisi>0){
	     				for(i=0;i<per.tatil.tatilsayisi;i++){
							printf("%d.0%d.%d  \n",per.tatil.tatiller[i][0],per.tatil.tatiller[i][1],per.tatil.tatiller[i][2]);}}
						else{
							printf("Personel �zin G�nlerini Kullanmam��t�r.\n");
						}
	                }   
	                 else{
	    	             printf("B�yle bir personel bulunmamaktad�r.\n");
		            }
	             }
                 do{
		         printf("\nPERSONEL SAYFA ���N 1(B�R)'� TU�LAYINIZ:");scanf("%d",&secim);
	             }while(secim!=1);
	             fclose(dosya);  
	             PersonelSayfa();
	             break;
	     case 2:
		     PersonelSayfa();
			 break;
		 default:
		     printf("uygun bir de�er giriniz.\n");
		     goto y;
			 break;   

	}	
}
void SikayetVeOneriGoster2(){
	int i;
	char gec;
	system("cls");
	printf("    PERSONEL ��KAYET VE �NER� B�LD�LER�\n________________________________________________\n");
    printf("\n[1]��KAYET\t[2]�NER�LER\n\n");
    printf("g�r�nt�lemek istedi�iniz se�ene�i se�iniz:");scanf("%d",&secim);
	char dosyauzantisi1[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\sikayet.txt";
	FILE *sikayet=fopen(dosyauzantisi1,"r");
	char dosyauzantisi2[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\oneri.txt";
	FILE *oneri=fopen(dosyauzantisi2,"r");
    switch(secim){
		case 1:
			printf("     ��KAYETLER\n");
			for(i=0;i<50;i++){printf("_");}printf("\n");
			while(fread(&per,sizeof(per),1,sikayet)==1){
		    printf("%s\n",per.SikayetveOneri.Sikayet);}
		    secim=0;
		    printf("\nGeri D�nmek i�in bir tu�a bas�n.\n");
		    gec=getch();
			PersonelSayfa();	
		    break;
		case 2:
			printf("     �NER�LER\n");
			for(i=0;i<50;i++){printf("_");}printf("\n");
			while(fread(&per,sizeof(per),1,oneri)==1){
			printf("%s\n",per.SikayetveOneri.Oneri);}
			secim=0;
			printf("\nGeri D�nmek i�in bir tu�a bas�n.\n");
		    gec=getch();
			PersonelSayfa();
			break;
		default:
			printf("Uygun bir se�im yap�n�z!\n");
			sleep(2);
			SikayetVeOneriGoster2();
	}
	fclose(sikayet);
	fclose(oneri);
}
void SikayetVeOneri2(){
	system("cls");
	printf("\n PERSONEL ��KAYET �NER� SAYFASI\n______________________________________________\n");
    char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
	printf("[1]��KAYET\t[2]�NER�LER\n\n");
	printf("��lem se�imi:");
	scanf("%d",&secim);
	switch (secim){
		case 1:
			strcat(dosyauzantisi,"sikayet.txt");
			FILE *sikayet=fopen(dosyauzantisi,"a+");
		    fflush(stdin);
			printf("Ma�azam�zla ilgili �ikayetinizi belirtiniz:");
			gets(per.SikayetveOneri.Sikayet);
			fwrite(&per,sizeof(per),1,sikayet) ;
			fclose(sikayet);
			sleep(2);
			PersonelAnasayfa();
			break;
		case 2:
			strcat(dosyauzantisi,"oneri.txt");
			FILE *oneri=fopen(dosyauzantisi,"a+");
		    fflush(stdin);
			printf("Daha  iyi bir hizmet i�in �nerileriniz...\n");
			gets(per.SikayetveOneri.Oneri);
			fwrite(&per,sizeof(per),1,oneri);
			fclose(oneri);
			sleep(2);
			PersonelAnasayfa();
			break;
		default:
			printf("Uygun  bir tercih giriniz...\n");
			sleep(1);
			PersonelAnasayfa();
	}  
}
void KampanyaSil(){
	int i;
	char kampanyakodu[50];
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\";
	for(i=0;i<100;i++){ printf("_");} printf("\n");
    printf("\nKampanyay� Silmek ��in Kampanya Kodunu Tekrar Giriniz: ");
    scanf("%s",kampanyakodu);
    strcat(kampanyakodu,".txt");
    strcat(dosyauzantisi,kampanyakodu);
    FILE *kampanyadosya=fopen(dosyauzantisi,"r");
	if(kampanyadosya==NULL){
	 	printf("KAYIT BULUNMAMAKTADIR.");
	 	sleep(3);
	 	YonetimAnasayfa();
	}
	else{
		while(fread(&kampanya,sizeof(kampanya),1,kampanyadosya)==1){
		printf("[1] Kampanya Genele A��k ise\n[2] Personeller i�in ise\nGiriniz: ");
		scanf("%d",&secim);
		if(secim==1){
			FILE *kampanyagenel=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt","r");
			FILE *temp1=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\ge�ici.txt","a");
			if(strcmp(kampanyakodu,kampanya.kampanyakodu)!=0){
				fwrite(&kampanya,sizeof(kampanya),1,temp1);
				fclose(temp1);
				fclose(kampanyagenel);
				remove(dosyauzantisi);
				remove("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt");
				rename("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\ge�ici.txt","C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt");
				}
		}
		else if(secim==2){
			FILE *kampanyaozel=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiOzel.txt","r");
			FILE *temp2=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\ge�icii.txt","a");
			if(strcmp(kampanyakodu,kampanya.kampanyakodu)!=0){
				fwrite(&kampanya,sizeof(kampanya),1,temp2);
				fclose(temp2);
				fclose(kampanyaozel);	
				remove(dosyauzantisi);
				remove("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiOzel.txt");
				rename("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\ge�ici.txt","C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiOzel.txt");
				}
		}
		}			
	}
	printf("�lgili hesap kay�tlardan silinmi�tir.\nKampanya Men�s�ne Y�nlendiriliyorsunuz...\n");
	sleep(2);
	KampanyaAnaSayfa();
}
	
void tatiller(){
	system("cls");
	FILE *tatildosya=fopen("tatiller.txt","ab+");
	int i;
		for(i=0;i<50;i++){printf("_");} printf("\n");
		printf("\n        AVM TAT�L TAKV�M�\n");
		for(i=0;i<50;i++){printf("_");} printf("\n\n");
		printf("Y�l i�indeki tatil say�s�n� girin: ");
		scanf("%d",&Boyut.saatler.tatilsayisi);
		Boyut.saatler.tatiller[Boyut.saatler.tatilsayisi][3];
	for(i=0;i<Boyut.saatler.tatilsayisi;i++){
		printf("%d. Tatil g�n�n� giriniz:\n",i+1);
		printf("Tatil g�n�n� girin: ");
		scanf("%d",&Boyut.saatler.tatiller[i][0]);
		printf("Tatil ay�n� girin: ");
		scanf("%d",&Boyut.saatler.tatiller[i][1]);
		printf("Tatil y�l�n� girin: ");
		scanf("%d",&Boyut.saatler.tatiller[i][2]);
		printf("\n");}
	
	printf("AVM Tatil G�nleri\n");
	for(i=0;i<Boyut.saatler.tatilsayisi;i++){
		printf("%d.0%d.%d  \n",Boyut.saatler.tatiller[i][0],Boyut.saatler.tatiller[i][1],Boyut.saatler.tatiller[i][2]);} //gun.ay.yil
	printf("\n\n");	
	fflush(stdin);
	fwrite(&Boyut,sizeof(Boyut),1,tatildosya);
	fclose(tatildosya);
	printf("Y�netim sayfas�na geri y�nlendiriliyorsunuz...\n");
	sleep(2);
	YonetimAnasayfa();
}
	
void isiklandirma(){
	system("cls");
	FILE *tatildosya=fopen("tatiller.txt","r");
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\";
	strcat(dosyauzantisi,Boyut.Magazakimlik);
	FILE *id=fopen(dosyauzantisi,"wb+");
	
	time_t time_1970;
	struct tm* time_detay;
	time_1970 = time(NULL);
	int isik,i,secim,tm,anasecim, gun,ay,yil,derece,say;
	
	time_detay = localtime(&time_1970);
	printf("Tarih: %.2d.%.2d.%4d\n", time_detay->tm_mday, time_detay->tm_mon+1, time_detay->tm_year+1900);
	printf("Saat : %.2d:%.2d\n\n", time_detay->tm_hour, time_detay->tm_min);
	for(i=0;i<50;i++){printf("_");} printf("\n");
	printf("\n\n    I�IKLANDIRMA MEN�S�\n");
	for(i=0;i<50;i++){printf("_");} printf("\n");
	
	gun=time_detay->tm_mday;
	ay= time_detay->tm_mon+1;
	yil=time_detay->tm_year+1900;
	
	if(tatildosya==NULL){
		fclose(tatildosya);
		printf("Hen�z Y�netici taraf�ndan �al��ma g�nleri atanmad�.\nAVM Y�netimiyle ileti�ime ge�iniz.\n");
		sleep(3);
		AnaMenu();
	}
	else{
		fread(&Boyut,sizeof(Boyut),1,tatildosya);
		printf("[1] I��kland�rmay� belirlemek i�in\n[2] ��k�� yapmak i�in\nGiriniz: ");
		scanf("%d",&anasecim);
		if(anasecim==1){
			for(i=0;i<=Boyut.saatler.tatilsayisi;i++){
				if(Boyut.saatler.tatiller[i][0]==gun&&Boyut.saatler.tatiller[i][1]==ay&&Boyut.saatler.tatiller[i][2]==yil){ 
					Boyut.saatler.aydinlatmaderecesi=0;
					printf("AVM Tatil g�n�ndedir.\n");
					say=0;
				}
			}
			if(say!=0){
				do{
					printf("Ma�azan�z�n ne kadar ayd�nlat�lmas� istedi�ini giriniz (Y�zde): ");
					scanf("%d",&Boyut.saatler.aydinlatmaderecesi);	
					printf("\n\nMa�azan�nn ayd�nlatmas� y�zde %d olarak ayarlanm��t�r.\n\n", Boyut.saatler.aydinlatmaderecesi);
					fwrite(&Boyut,sizeof(Boyut),1,id);
					fclose(id);
					printf("[1] Ayd�nlatmay� De�i�tirmek i�in\n[2] C�k�� yapmak i�in\nGiriniz: ");
					scanf("%d",&secim);
				}
				while(secim==1);
				sleep(2);
				YonetimAnasayfa();
			}
		}
		else if(anasecim=2){
			Boyut.saatler.aydinlatmaderecesi=0;
			printf("Y�netim sayfas�na y�nlnediriliyorsunuz...\n\n");
			sleep(2);
			fwrite(&Boyut,sizeof(Boyut),1,id);
			fclose(id);
			YonetimAnasayfa();
		}
	}
	fclose(tatildosya);
}
	
void MagazaYapilandirma(){
	system("cls");
	FILE *yapidosya=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\magazayapilandirma.txt","w+");
	int i, n;
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("\n      MA�AZA YAPILANDIRMA SAYFASI \n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("AVM'deki magazalardaki boyut tip sayisi\n(AVM'de bulunan magaza boyutlarinin kac farkli tipte oldugunun sayisi)\nGiriniz: ");
	scanf("%d",&Boyut.Yapi.tipadet);
		Boyut.Yapi.boyut=(int *)malloc(sizeof(int)*Boyut.Yapi.tipadet[0]);	
	
	back:	
	for(n=0;n<Boyut.Yapi.tipadet[0];n++){
		printf("%d. ma�aza metrekare boyudunu giriniz: ",n+1);
		scanf("%d",&Boyut.Yapi.boyut[n]);
		if(Boyut.Yapi.boyut[n]>1000){
			printf("�st Limiti A�t�n�z.\nMetrekare Giri� Ekran�na Yeniden Y�nlendiriliyorsunuz.\n\n");
			goto back;}
		printf("  %d metrekarelik magazan�n adet say�s�n� girin: ",Boyut.Yapi.boyut[n]);
		scanf("%d",&Boyut.Yapi.magazasayisi[n]);}
	
	printf("\n\n");
	fwrite(&Boyut,sizeof(Boyut),1,yapidosya);
	fclose(yapidosya);
	printf("\nYap�land�rma i�leminiz ba�ar�yla tamamlanm��t�r\n");
	sleep(2);
	YonetimAnasayfa();
}
void MagazaKayit(){
	system("cls");
	int i;
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("       MA�AZA KAYIT MEN�S�\n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	a:
	printf("Ma�azan�za Kimlik Giriniz\n(Ma�aza kimli�i olu�tururken ingilizce harfler kullan�n�z)\nKimlik Olu�turunuz: ");
	scanf("%s",Boyut.Magazakimlik);
	strcat(Boyut.Magazakimlik,".txt");
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\";
	strcat(dosyauzantisi,Boyut.Magazakimlik);
	FILE *magaza = fopen(dosyauzantisi,"r");
	if(magaza==NULL){
		fclose(magaza);
		magaza=fopen(dosyauzantisi,"w");
		
		printf("Ma�azan�z olu�turulmu�tur. Bilgilerinizi %s dosyas�ndan ula�abilirsiniz.\n\nMagaza Kiralama Men�s�ne Y�nlendiriliyorsunuz...\n\n",Boyut.Magazakimlik);
		sleep(2);
		fwrite(&Boyut,sizeof(Boyut),1,magaza);
		fclose(magaza);
		MagazaKiralama();
		printf("\nMa�aza Kay�tlanma ��lemleriniz ba�ar�yla tamamlanm��t�r.\n");
		sleep(2);
		YonetimAnasayfa();}
	else{
		printf("Ayn� Magaza Kimli�inden Bulunmaktad�r.\nYeni bir kimlik i�in tekrar y�nlendiriliyorsunuz..\n\n");
		sleep(1);
		goto a;
	}
}
    
void MagazaKiralama(){
	system("cls");
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\";
	strcat(dosyauzantisi,Boyut.Magazakimlik);
	FILE *magaza=fopen(dosyauzantisi,"wb+");
	FILE *yapidosya=fopen("C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\magazayapilandirma.txt","r");
	if(yapidosya==NULL){
		printf("\nMa�aza Yap�land�rmas� yap�lmam��t�r. Y�netim ile ileti�ime ge�iniz!\n\n");
		fclose(magaza);
		sleep(2);
		AnaMenu();}
	else{
		float elektrik,su,dogalgaz;
		int yonlendirici, i, m, say,s, cevap;
		float kira,toplam,alan;
		for(i=0;i<100;i++){printf("_");}printf("\n");
		printf("                 MA�AZA K�RALAMA MEN�S�\n");
		for(i=0;i<100;i++){printf("_");}printf("\n");
		while(fread(&Boyut,sizeof(Boyut),1,yapidosya)==1){
			printf("Ma�aza Ad�n� Giriniz: ");
		fflush(stdin);
		gets(Boyut.Magazaisim);
		printf("Ma�azan�n �al��ma sekt�r�n� girin: ");
		fflush(stdin);
		gets(Boyut.Sektor);
		printf("\n\n");
			for(s=0;s<Boyut.Yapi.tipadet[0];s++){
				printf("%d metrekarelik ma�aza se�imi i�in [%d]\n",Boyut.Yapi.boyut[s],s);
			}
		}
		in:
		printf("�stedi�iniz ma�aza boyut se�imini giriniz: ");
		scanf("%d",&s);
		if(Boyut.Yapi.boyut[s]<=1000){
			if(Boyut.Yapi.boyut[s]<45){
				alan=Boyut.Yapi.boyut[s];
				kira=alan;							
				kira*=138.5;}	
			else if(45<=Boyut.Yapi.boyut[s]&&Boyut.Yapi.boyut[s]<400){
				alan=Boyut.Yapi.boyut[s];
				kira=alan;				
				kira*=200;}		
			else{
				alan=Boyut.Yapi.boyut[s];
				kira=alan;				
				kira*=273.5;}
			
			elektrik=alan*1.92;
			su=alan*2.53;
			dogalgaz=alan*2.98;
			toplam=kira+dogalgaz+elektrik+su+dogalgaz;
	
			if(Boyut.Yapi.magazasayisi[s]==0){
				printf("�u anda mevcut boyuttaki magazalar doludur.\nTekrar se�im yapmak i�in [1]\nAna men�ye d�nmek i�in [2]");
				scanf("%d",&cevap);
				if(cevap==1){
					printf("\n");
					goto in;}
				else{
					goto tb;}
			}
			else{
				printf("\n%.f metrekarelik alan tahsis edilebilir.\n",alan);
				printf("Ma�azan�z�n Ayl�k Kira Bedeli: %.2f\n",kira);
				printf("�u anda bulunan ma�aza: %d adet\n\n",Boyut.Yapi.magazasayisi[s]);
				printf("Dogalgaz Tutar�: %.2f\n",dogalgaz);
				printf("Elektrik Tutar�: %.2f\n",elektrik);
				printf("Su Tutar�: %.2f\n\n",su);
				printf("Toplam Gider: %.2f\n\n",toplam);
	
				printf("\n[1] Ma�azay� Kiralamak\n[2] Kiralama Men�s�ne D�nmek\n[3] Ma�aza Men�s�ne D�nmek\n��leminizi Giriniz: ");
 				scanf("%d",&cevap);
 				if(cevap==1){
 					Boyut.Gider.Kira=kira;
 					Boyut.Gider.alan=alan;
 					Boyut.Gider.Fatura.Elektrik=elektrik;
 					Boyut.Gider.Fatura.Su=su;
 					Boyut.Gider.Fatura.Dogalgaz=dogalgaz;
 					Boyut.Gider.Toplam=toplam;
					printf("%.f metrekarelik ma�azan�z %.3f kira bedeliyle tahsis edilmi�tir.\n",Boyut.Gider.alan,Boyut.Gider.Kira);
					Boyut.Yapi.magazasayisi[s]-=1;
					say=1;		
					fwrite(&Boyut,sizeof(Boyut),1,magaza);
					fclose(magaza);
					printf("[1] Ana Men�ye D�nmek i�in\n[2] Y�netim Men�s�ne D�nmek i�in\nGiriniz: ");
					scanf("%d",&yonlendirici);
					if(yonlendirici==1){
						AnaMenu();
					}
					else if(yonlendirici==1){
						YonetimAnasayfa();
					}
				}
				else if(cevap==2){
					tb:
					printf("\n");
					say=0;
					goto in;	
				}
				else{
					if(say==1){
						printf("%.f metrekarelik alan kiralanm��t�r.\n",Boyut.Gider.alan);
						printf("Kira Bedeli: %.3f",Boyut.Gider.Kira);
					}
					else{
						Boyut.Gider.Kira=0;
						Boyut.Gider.Toplam=0;
						Boyut.Gider.Fatura.Dogalgaz=0;
						Boyut.Gider.Fatura.Elektrik=0;
 						Boyut.Gider.Fatura.Su=0;
					}
				}
			}
		}
	}
	printf("\nKay�tlanma Men�s�nden ��k�yorsunuz...\n");
	fclose(yapidosya);
}

void MagazayiGoster(){
	system("cls");
	int i;
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("  MA�AZA B�LG�LER� G�R�NT�LEME SAYFASI\n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	int secim,arasecim;
	b:
	printf("\nMa�aza Kimli�inizi Giriniz: ");
	scanf("%s",Boyut.Magazakimlik);
	strcat(Boyut.Magazakimlik,".txt");
	char dosyauzantisi[100]="C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\";
	strcat(dosyauzantisi,Boyut.Magazakimlik);
	FILE *magaza = fopen(dosyauzantisi,"r");
	FILE *id=fopen(dosyauzantisi,"r");
	FILE *tatildosya=fopen("tatiller.txt","r");
	if(magaza==NULL){
		fclose(magaza);
		printf("\n\nMa�aza kimlik numaras� ge�ersizdir.\n\n[1] Ma�aza Kay�t Men�s�\n[2] Tekrar Giri� Yapma\n[3] Ana Men�ye D�nmek\nGiriniz: ");
		scanf("%d",&secim);
		if(secim==1){
			MagazaKayit();}
		else if(secim==2){
			goto b;}
		else{
			AnaMenu();}
	}
	else{
		if(fread(&Boyut,sizeof(Boyut),1,magaza)==1){
		printf("\n\nHo�geldiniz!\n");
		x:
		for(i=0;i<100;i++){printf("_");}printf("\n");
		printf("[1] Ma�azan�z�n Gider Kay�tlar�n� G�rme\n[2] I��kland�rma Ayarlar�\n[3] Ma�aza De�i�ikli�i\nGiriniz: ");
		scanf("%d",&secim);
			switch(secim){
				case 1:
					if(Boyut.Gider.alan>0){
						printf("\n\n");
						printf("MA�AZA ADI: %s\n",Boyut.Magazaisim);
						printf("MA�AZA SEKT�R�: %s\n",Boyut.Sektor);
						for(i=0;i<80;i++){printf("_");}printf("\n");
						printf("G�DERLER:\n");
						printf("Ma�aza boyutu: %.f\n",Boyut.Gider.alan);
						printf("Ma�aza kiras�: %.2f\n",Boyut.Gider.Kira);
						printf("Do�algaz Tutar�: %.2f\n",Boyut.Gider.Fatura.Dogalgaz);
						printf("Elektrik Tutar�: %.2f\n",Boyut.Gider.Fatura.Elektrik);
						printf("Su Tutar�: %.2f\n\n",Boyut.Gider.Fatura.Su);
						printf("Toplam Gider: %.2f\n\n",Boyut.Gider.Toplam);
						fclose(magaza);
						printf("[1] Geri d�nmek i�in\n[2] Ana Men�ye ��kmak i�in\nGiriniz: ");
						scanf("%d",&arasecim);
						if(arasecim==1) goto x;
						else if(arasecim) AnaMenu();}
					else{
						printf("\nKayd�n�z olu�turulmu�tur fakat mevcut bir ma�azan�z bulunmamaktad�r\nMa�aza Kiralama men�s�ne y�nlendiriliyorsunuz...\n");
						fclose(magaza);
						sleep(3);
						MagazaKiralama();}
					break;
				case 2:
					if(id==NULL){
						printf("\nHen�z taraf�n�zdan ���kland�rman�z belirlenmemi�tir.\nI��kland�rma Men�s�ne Y�nlendiriliyorsunuz...\n\n");
						fclose(magaza);
						sleep(1);
						isiklandirma();}
					else{
						fread(&Boyut,sizeof(Boyut),1,id);
						if(Boyut.saatler.aydinlatmaderecesi>0){
							printf("\nMa�azan�n ayd�nlatmas� y�zde %d olarak ayarlanm��t�r.\n\n",Boyut.saatler.aydinlatmaderecesi);
							for(i=0;i<100;i++){printf("_");}printf("\n");
							printf("[1] De�i�iklik i�in\n[2] ��k�� yapmak i�in\nGiriniz: ");
							scanf("%d",&secim);
								if(secim==1){
									fclose(magaza);
									isiklandirma();}
							}
						else{
							printf("Ma�aza kapal�d�r.\n[1] A��l�� i�in\n[2] ��k�� yapmak i�in\nGiriniz: ");
							scanf("%d",&secim);
								if(secim==1){
									fclose(magaza);
									isiklandirma();}
						}
					}	
					break;
				case 3:
					remove(dosyauzantisi);
					FILE *magaza = fopen(dosyauzantisi,"w");
					MagazaKiralama();
					fwrite(&Boyut,sizeof(Boyut),1,magaza);
					fclose(magaza);
					YonetimAnasayfa();
				break;
			}
		}
		else{
			printf("\nMevcut kayd�n�z i�leme ge�irilememi�tir.\n[1] Ana Men�ye D�nme\n[2] Kiralama Men�s�\n Giriniz:");
			scanf("%d",&secim);
			if(secim==1)
				AnaMenu();
			else if(secim==2)
				fclose(magaza);
				MagazaKayit();	
		}
		fclose(magaza);
	}
}
void MagazaMenu(){
	system("cls");
	FILE *yapidosya=fopen("magazayapilandirma.txt","r");
	int secim, arasecim, i;
	
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("\n           MA�AZA MEN�S�\n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	b:
	printf("[1] Ma�aza g�r�nt�leme\n[2] Ma�aza Kayd� Olu�turma\n[3] Ana Men�ye D�nme\n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("Giriniz: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			MagazayiGoster();
			break;
		case 2:
			if(yapidosya==NULL){
				printf("Hen�z y�netici taraf�ndan ma�aza yap�land�r�lmas� olu�turulmam��t�r.\nAVM Y�netimiyle ileti�ime ge�iniz.\n");
				sleep(1);
				AnaMenu();}
			else{
				MagazaKayit();}
			break;
		case 3:
			AnaMenu();
			break;
		default:
			printf("Uygun De�er Girmediniz.\nAna Men�ye Y�nlendiriliyorsunuz...\n");
			sleep(2);
			MagazaMenu();
		}
	fclose(yapidosya);
}

void puanGirdi(){
	int v=0,i;
	char dosyauzantisi[100];
	char kullaniciKont[100];
	FILE *dd;
	m:
	system("cls");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("        PUAN G�NCELLEME EKRANI\n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("[1] M��teri Puan�\n[2] Personel Puan�\nGiriniz: ");
	scanf("%d",&v);
	if(v==1){
		printf("\nM��terinin Kullan�c� Ad�n� Girin: ");
		scanf("%s",kullaniciKont);
		strcat(kullaniciKont,".txt");
		strcpy(dosyauzantisi,"C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\");
		strcat(dosyauzantisi,kullaniciKont);
		fflush(stdin);
		dd=fopen(dosyauzantisi,"r+");
		fseek(dd,6*sizeof(cust),SEEK_SET);
		printf("Puan yaz�n�z: ");
		scanf("%s",&cust.IndirimKarti.Puan);
		fwrite(&cust,sizeof(cust),1,dd);
		fclose(dd);
		fflush(stdin);
	}
	else if(v==2){
		printf("\nPersonelin Kullan�c� Ad�n� Girin: ");
		scanf("%s",kullaniciKont);
		strcat(kullaniciKont,".txt");
		strcpy(dosyauzantisi,"C:\\Users\\�EYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\");
		strcat(dosyauzantisi,kullaniciKont);
		fflush(stdin);
		dd=fopen(dosyauzantisi,"r+");
		fseek(dd,sizeof(per)*16,SEEK_SET);
		printf("Puan yaz�n�z: ");
		scanf("%d",&per.IndirimKarti.Puan);
		fwrite(&per,sizeof(per),1,dd);
		fclose(dd);
		fflush(stdin);	
	}
	else{
		printf("Hatal� Girdiniz");
		v=0;
		goto m;
	}
	printf("\n\n��kmak i�in E, yeniden bakmak i�in H giriniz: ");
	fflush(stdin);
	if(toupper(getch())== 'H'){
		printf("\n\n");
		puanGirdi();
	}
	else if(toupper(getch())== 'E'){
		printf("\n\n");
		YonetimAnasayfa();
	}
}
