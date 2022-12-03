
	
	/* *************************************************************************************************************************
		*-																											     	-*
		|			   	  Burak ATEŞ ( Öğr. No.211451001) Algorithm and Programming Homework 2							    |
		|	 Menü sayesinde listeleme, ekleme, çıkarma, önceki kayıda gitme, sonraki kayıda gitme işlemlerini sağlayan		|
		-*    ve Öğrenci ad, soyad, numara, vize notu ve final notu bilgilerini içeren öğrenci otomasyon uygulaması kodları.*-
		
	 *************************************************************************************************************************** */                                    


#include <stdio.h>												// Standart giriş çıkış kütüphanesi
#include <stdlib.h>												// malloc komutu için kütüphane
#include <string.h>												// strcpy için kütüphane

struct node														// Öğrenci numarası, adı, soyadı, vize notu ve final notu için node adında struct oluşturuldu.
{
	int numara;													// Öğrenci numarası tanımlaması
	char ad[30];												// Öğrenci adı tanımlaması (hafızada 30 karakterlik yer ayrıldı)
	char soyad[30];												// Öğrenci soyadı tanımlaması (hafızada 30 karakterlik yer ayrıldı)
	int final;													// Öğrenci final notu tanımlaması
	int vize;													// Öğrenci vize notu tanımlaması
																
	struct node *onceki;										// Bağlı listede önceki düğüme gitmek için.														
	struct node *sonraki;										// Bağlı listede sonraki düğüme gitmek için.

};

typedef struct node bilgiler;									// struct node adlı yapı kullanım kolaylığı için "bilgiler" olarak değiştirildi
bilgiler *root=NULL;											//typedef kodu veri türü tanımlamak için kullanıldı.
						 										//bilgiler düğümünün ilk gösterdiği yer (root) NULL olarak atandı çünkü henüz düğümde eleman yok.	
int cnt=0;														// tanımlama ve atama işlemi

																/* ilk olarak main ile başlandığından ve c dili yukardan aşağı çalıştığından 
																hata almamak için öncelikle fonksiyonların prototipleri tanımlandı. */
void dosyadanBagliListeyeAktar();								//  fonksiyon prototipi tanımlama.
void ogrenciEkle (int n, char *a, char *s, int v, int f);		// fonksiyon prototipi tanımlama.
void ogrenciSil();												//  fonksiyon prototipi tanımlama.
void bilgileriDosyayaYaz();										//  fonksiyon prototipi tanımlama.
void bilgileriListele();										//  fonksiyon prototipi tanımlama.


int main()																				// main kapsamı
{		
	dosyadanBagliListeyeAktar();														/* önceden yazılan bilgilerin oluşturulan txt dosyasında kaydedilmesini  
																						ve sistem çalışınca burdaki bilgilerin sisteme aktarılmasını yani bilgileri okumayı sağlayan fonksiyon*/							
																						// bu fonksiyon sayesinde listenin okunması sağlanıyor.
//	printf("dosyadaki veriler basarili bir sekilde bagli listeye aktarildi \n \n\n");// yukarıdaki işlemin doğru bir şekilde yapıldığı mesajını ekrana bastıran kod
	printf("|***----------------------------------------------------***|\n");	    	// süsleme
	printf("\tOGRENCI OTOMASYON SISTEMINE HOS GELDINIZ\n");					     		// karşılama mesajını bastıracak kod.
	printf("|***----------------------------------------------------***|\n\n");			// süsleme
		
	int secim;																			// int türünde secim adlı değişken tanımlandı menüde kullanılacak
	int numara,  vize, final;															// int türünde numara, vize, final isimli değişkenler tanımlandı
	char ad[30], soyad[30]; 															// char türünde ad ve soyad değişkenleri tanımlandı	
	while(1)																			// sonsuz dögü oluşturuldu
	{	printf("\t|------------------------------------|");								// süsleme
		printf("\n\t|--OGRENCI OTOMASYON SISTEMI MENUSU--|\n");							// menü mesajı
		printf("\t|------------------------------------|\n\n");							// süsleme
		printf("\n---Lutfen Islem Yapmak Istediginiz Numarayi Seciniz---\n\n");			// secim mesajı
		
		printf("\t\t1--> OGRENCI EKLE \n");												// ekleme işlemi yapabilmek için
		printf("\t\t2--> OGRENCI SIL \n");												// silme işlemi yapabilmek için
		printf("\t\t3--> KAYITLI BILGILERI LISTELE \n");								// listeleme işlemi yapabilmek için
		printf("\t\t4--> BILGILERI DOSYAYA YAZDIR \n");									// girilen bilgileri dosyaya yazdırma işlemi yapabilmek için
		//printf("\t\t5--> DOSYADAN AKTAR \n"); 
		printf("\t\t0--> CIKIS \n");													// menüden çıkmak için
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t...by/burakates...");			// süsleme
		printf("Seciminiz	:");														// Seciminiz	: mesajını ekrana bastıracak kod.
		scanf("%d", &secim);															// klavyeden girilen seçimi okuyacak kod.
		switch(secim)	{																// seçim değişkenini kontrol etmek için switch case kullanıldı
			case 1:																		// 1 e basılınca ekleme işleminin gerçekleşmesini sağlayan kod
			printf(" \n\tEklenecek Ogrenci Bilgilerini Giriniz\n");						// Eklenecek Ogrenci Bilgilerini Giriniz mesajını ekrana bastıracak kod
			printf("\t|-----------------------------------|\n");						// süsleme
			printf("ogrenci numarasi  :");												// ogrenci no  : mesajını ekrana bastıracak kod 
			scanf("%d", &numara);														// klavyeden girilen bilgiyi okuyan kod 
			printf("ogrenci ad  :");													// ogrenci ad  : mesajını ekrana bastıracak kod 
			scanf("%s", &ad); 															// klavyeden girilen bilgiyi okuyan kod 
			printf("ogrenci soyad :");													// ogrenci soyad  : mesajını ekrana bastıracak kod 
			scanf("%s", &soyad); 														// klavyeden girilen bilgiyi okuyan kod 			
			printf("ogrenci vize  :");													// ogrenci vize  : mesajını ekrana bastıracak kod 
			scanf("%d", &vize); 														// klavyeden girilen bilgiyi okuyan kod 			
			printf("ogrenci final :");													// ogrenci final :mesajını ekrana bastıracak kod  
			scanf("%d", &final); 	 													// klavyeden girilen bilgiyi okuyan kod 
			ogrenciEkle(numara, ad, soyad, vize, final);								// kullanıcı tarafından girilen bilgiler ogrenciEkle fonksiyonuna gönderiliyor
			break;																		// bu işlemden çıkış yapılıyor									
			
			case 2: ogrenciSil();														// 2 ye basılınca silme işleminin gerçekleşmesini sağlayan kod
			break;																		// bu işlemden çıkış yapılıyor
				
			case 3: bilgileriListele();													// 3 e basılınca listeleme işleminin gerçekleşmesini sağlayan kod
			break;																		// bu işlemden çıkış yapılıyor
			
			case 4: bilgileriDosyayaYaz();												// 4 e basılınca dosyaya yazdırma işleminin gerçekleşmesini sağlayan kod
			break;																		// bu işlemden çıkış yapılıyor
			
		/*	case 5: dosyadanBagliListeyeAktar();										//  işleminin gerçekleşmesini sağlayan kod
			break;		*/																// bu işlemden çıkış yapılıyor
			
			case 0: return 0;															// menüden çıkış işlemi			
		    default : printf("\n!!!YANLIS NUMARA SECTINIZ, LUTFEN MENUDEN BIR NUMARA SECINIZ!!! \n\n");	// menüdeki sayılar dışında başka bir sayıya basılırsa hata vermeyi ve ekrana uyarı mesajı yazmayı sağlayan kod			
		}
	}
}

void dosyadanBagliListeyeAktar()															/* ! önceden yazılan bilgilerin oluşturulan txt dosyasında kaydedilmesini  
																							ve sistem çalışınca burdaki bilgilerin sisteme aktarılmasını yani bilgileri okumayı sağlayan fonksiyon !!!*/
	{
	
	FILE *dosya = fopen("ogrenciBilgileri.txt", "r");										// ogrenciBilgileri adındaki txt dosyasını açma işlemi // dosya ile ilgili işlemler yapılırken *dosya pointeri kullanılır
	while(!feof(dosya))																		// dosyanın sonuna ka
	{
		int n, v, f;																		// tanımlama
		char a[30], s[30];																	// tanımlama
		fscanf(dosya, "%d%s%s%d%d", &n,a,s,&v,&f);											// fscanf ile dosyadaki verilerin okunması sağlanıyor.
		ogrenciEkle( n,a,s,v,f);
	}
	fclose(dosya);																			// dosyayı kapatma işlemi
	system("cls");																			// ekranı temizlemek için
	}


void ogrenciEkle (int n, char *a, char *s, int v, int f) 		// ogrenciEkle adında bir fonksiyon oluşturuldu ve içine 5 adet parametre atandı. Fonksiyonların geriye dönmesine ihtiyacımız olmadığı için hepsi void olarak oluşturuldu
{																// Bu fonksiyon listemize öğrenci eklemek için kullanılacak.																
	system("cls");												// Ekleme işlemi yapılırken ekranın temizlenmesi ve daha güzel görünmesi için

	bilgiler *ogr= (bilgiler*) malloc(sizeof(bilgiler));		// malloc kodu sayesinde hafızada yer ayrıldı ve ogr göstericisi yapıldı
	ogr->numara= n;												// ogr göstericisinin numarası n olarak atandı
	strcpy(ogr->ad, a);											// ogr göstericisinin ad'ı a olarak atandı. ad değişkeni karakter olduğu için strcpy kullanıldı
	strcpy(ogr->soyad, s);										// ogr göstericisinin soyad'ı s olarak atandı. soyad değişkeni karakter olduğu için strcpy kullanıldı
	ogr->vize= v;												// ogr göstericisinin vize'si v olarak atandı
	ogr->final= f;												// ogr göstericisinin final'i f olarak atandı

	if (root==NULL)												// ilk gösterici NULL u gösteriyorsa liste boş demektir								
	{
		root=ogr;														// ilk düğüm atandı
		root->sonraki= root;											// çift yönlü dairesel bağlı liste olduğu için ilk düğümün next i kendini gösteriyor
		root->onceki= root;												// çift yönlü dairesel bağlı liste olduğu için ilk düğümün prev i(öncesi) kendini gösteriyor
		cnt++;
		printf("%d Numarali Ilk Ogrenci Eklendi \n", root->numara);			  //...Numarali ilk ogrenci eklendi mesajını ekrana bastıracak kod
	}
	
	else																// listede en az bir düğüm olduğu durum
	{
		bilgiler * p= root;												// geçici düğüm oluşturuldu
		while(p->sonraki!=root)											// p'nin son düğüme kadar gitmesini sağlayan kod 
		p= p->sonraki;													// p son düğüm oldu
		
																		 	 //eklenen düğümün... 
		ogr->sonraki= root;												 	 // listenin başına...
		root->onceki= ogr;									   		 		 // eklenmesini...
		root=ogr;										     				 // sağlayan kodlar.
		p->sonraki= root;													 // son düğümle... 
		root->onceki= p;													// root u bağlayan kodlar.
		cnt++;																// cnt yi bir eksiltme işlemi. ekleme yapıldığı için
		printf("%d Numarali Ogrenci Listeye Eklendi \n", root->numara);		// ...Numarali ogrenci listeye eklendi mesajını ekrana bastıracak kod.
	}
}


void ogrenciSil()																/*ogrenciSil adında bir fonksiyon oluşturuldu. Listeden öğrenci silmek için kullanılacak
																				Fonksiyonların geriye dönmesine ihtiyacımız olmadığı için hepsi void olarak oluşturuldu*/
{
	system("cls");																// silme işlemi yapılırken ekranın temizlenmesi için

	if (root==NULL)																// bağlı listenin boş olması durumunu gösterir.			
	{
		printf("Listede Kayıtlı Ogrenci Yok, Silme Işlemi Yapılamadı \n");	}	/* 	bağlı liste boşsa yani listede öğrenci yoksa 		
																				 silme işleminin yapılamayacağını gösteren "listede kayıtlı ogrenci yok" mesajını ekrana bastıracak kod.*/
	else																		// bağlı listenin boş olmadığı durum
	{	int ogrNo;																// int türünde ogrNo değişkeni tanımlandı, silme işlemi için kullanılacak												
		printf("\nSilinecek Ogrencinin Numarasini Yaziniz \n ") ;				// "Silinecek ogrencinin numarasini yaziniz" mesajını ekrana bastıran kod
		scanf ("%d", &ogrNo);													// silme işlemi için seçilen öğrenci numarasını klavyeden okuyan kod.
		
		if(cnt==1 && root->numara == ogrNo)										// listede bir düğüm olduğunu gösteren kod. girilen ogrNo root un gösterdiği no ya yani listedeki tek öğrencinin no suna eşit olduğu durum.
		{	
			printf("Kayitli Son Ogrenci Silindi, Liste Bos \n");		 		// Kayitli son ogrenci silindi, liste bos  mesajını ekrana bastıracak kod.
			free(root);															// silme işlemi
			root==NULL;															// son öğrenci de silindiğinden liste boş kaldığı için ilk göstericinin NULL u göstermesini sağlayan kod.
			cnt--;																// cnt yi bir eksiltme işlemi
		}
		else if (cnt!=1 && root->numara == ogrNo)								// listede birden fazla düğüm olduğunu gösteren kod. girilen ogrNo root un gösterdiği no ya eşit olduğu durum. (silinmek istenen)
		{	
			printf("%d Numarali Ogrenci Silindi \n", root->numara);				// ..numarali ogrenci silindi mesajını ekrana bastıracak kod
			bilgiler *p = root;													// geçici düğüm oluşturuldu
			while(p->sonraki!=root)												// p'den sonraki düğüm ilk gösterilene eşit olmadığı sürece çalışacak döngü
			p= p->sonraki;														// atama
			
			bilgiler *p2 = root->sonraki;										// silinecek düğümün(root) sonraki düğümünü root yapacak atama işlemi. geçici p2 ile tutuluyor
			free(root);															// silme işlemi
			root=p2;															// atama
				
			root->onceki= p;													// düğümleri bağlama ilk
			p->sonraki= root;													// düğümleri bağlama son
			cnt--;																// cnt yi bir eksiltme işlemi
		}	
		else																	// başka bir düğümü silme durumu
		{
			bilgiler *g = root;													// root tan başlayan geçici değişken işlemi. g: geçici
			bilgiler *go = root;												// root tan başlayan geçici değişken işlemi. go: g'den önceki düğüm
			bilgiler *gs = root;												// root tan başlayan geçici değişken işlemi. gs: g'den sonraki düğüm
					
			while(g->sonraki!=root)												// g'den sonraki düğüm ilk gösterilene eşit olmadığı sürece çalışacak döngü
			{
				if(g->numara==ogrNo)											// gösterine no ile girilen no nun aynı olması durumu
				{			
					printf("%d Nummarali Ogrenci Silindi \n", g->numara );		// ...numarali ogrenci silindi mesajını ekrana bastıracak kod
					gs= g->sonraki;
					free(g);													// silme işlemi
					go->sonraki= gs;											// düğümleri bağlama işlemi
					gs->onceki= go;												// düğümleri bağlama işlemi	
					cnt--;														// cnt yi bir eksiltme işlemi	
					break; 														// döngüyü kırma işlemi
				}
				go= g;															// atama
				g= g->sonraki;
			}
			if(g->numara==ogrNo)												// son düğümü silme işlemi. while, kod gereğison düğüme gitmiyor o yüzden buna ihtiyaç var
				{
					printf("%d Nummarali Ogrenci Silindi \n", g->numara );		// ..numarali ogrenci silindi mesajını ekrana bastıracak kod
					free(g);													// silme işlemi
					go->sonraki= root;											// son düğümün sonrakisi root u gösterdiğinden dolayı son düğüm de silindiğinden root a bağlama işlemi
					root->onceki= go;											// bağlama işlemi
					cnt--;														// cnt yi bir eksiltme işlemi
				}
		} } } 

void bilgileriDosyayaYaz()																	// bilgileriDosyayaYaz adında fonksiyon tanımlandı. sisteme girilen bilgiler oluşturulan txt dosyasına yazılacak ve kaydedilecek
	{
		if(root==NULL)																		// bağlı listenin boş olduğu durum
		{
			printf("Liste Bostur, Dosyaya Kaydedilecek Bilgi Yok \n");						//liste bostur, dosyaya kaydedilecek bilgi yok mesajını ekrana bastıracak kod
		}		
		else																				// listenin boş olmadığı durum
		{
			bilgiler * p= root;														    	// geçici değişken oluşturuldu
			FILE *dosya = fopen("ogrenciBilgileri.txt", "w");								// ogrenciBilgileri adında .txt türünde bir dosya otomatik oluşturuldu. yazma modunda açıldı (w)
			while(p->sonraki!=root) {													   	// döngü		
				fprintf( dosya, "%d %s %s %d %d \n", p->numara, p->ad, p->soyad, p->vize, p->final); // dosyaya yazdırma işlemi
				p= p->sonraki;				
			}
			fprintf( dosya, "%d %s %s %d %d ", p->numara, p->ad, p->soyad, p->vize, p->final);   // while döngüsü son düğüme gittiğinde gerekli bilgilerin ekrana yazdırılması için aynı kod tekrar yazıldı
			fclose(dosya);																	// dosyayı kapatma işlemi
			printf("Girilen Bilgiler Basarili Bir Sekilde Dosyaya Kaydedildi\n");		   	// Girilen Bilgiler Basarili Bir Sekilde Dosyaya Kaydedildi mesajını ekrana bastıracak kod	 
		}
	}
		
	void bilgileriListele()																	//bilgileriListele adında fonksiyon tanımlandı. Tüm öğrenci bilgilerini listelemek için kullanılacak.
{	
	system("cls");																			//listeleme işlemi yapılırken ekranın temizlenmesi için
	if(root==NULL)																			// bağlı listenin boş olduğu durum
	{
		printf("Liste Bos, Listelenecek Ogrenci Yok \n");									// "liste bos, listelenecek ogrenci yok" mesajını ekrana bastıran kod.
	}
	else																					// yazdırılacak öğrencinin olduğu durum
	{
		bilgiler * p= root;																	// geçici değişen oluşturuldu
		while(p->sonraki!=root)																// p nin son düğüme kadar gitmesini sağlayan kod 
		{	
			printf("%d Numarali Ogrencinin Adi: %s Soyadi: %s Vize Notu: %d Final Notu: %d \n", p->numara, p->ad, p->soyad, p->vize, p->final);	
			p= p->sonraki;
		}
		printf("%d Numarali Ogrencinin Adi: %s Soyadi: %s Vize Notu: %d Final Notu: %d \n", p->numara, p->ad, p->soyad, p->vize, p->final); // while döngüsü son düğüme gittiğinde gerekli bilgilerin ekrana yazdırılması için aynı kod tekrar yazıldı
	}
}
