// Samet BELLUR
// �ift Y�nl� Ba�l� Liste ve Fonksiyonlar�

#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int data;//veri
	struct node *next;// Sonraki D���m ��aret�isi
	struct node *prev;// �nceki D���m ��aret�isi
};

struct node * start = NULL;//�lk d���m� bilmeliyiz

struct node* makenode (int idata){ //Bu fonksiyon d���m �retir, ("idata" incoming data yani gelen veri anlam�nda)
	
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data= idata;
	newnode->next= NULL;
	newnode->prev= NULL;
	
	return(newnode);
}

void addToFirst (int idata){//Bu fonksiyon ba�tan d���m ekler ("idata" anlam� incoming data yani gelen veri dir)
    struct node * willBeAdded = makenode (idata);//D���m olu�turup atad�k ("willBeAdded" eklenecek d���m anlam�nda)
    
    if (start == NULL){//Bunun eklenen ilk d���m olup olmad���n� kontrol etmeliyiz
		start= willBeAdded;
		printf("---EKLENDI---\n");
	}
	else {
		start->prev= willBeAdded;
		willBeAdded->next= start;
		start= willBeAdded;
		}
	system ("pause");
	system ("cls");
}

void addToLast (int idata){//Bu fonksiyon sondan d���m ekler ("idata" anlam� incoming data yani gelen veri dir)
	struct node * willBeAdded = makenode (idata);//D���m olu�turup atad�k ("willBeAdded" eklenecek d���m anlam�nda)
	
	if (start == NULL){//Bunun eklenen ilk d���m olup olmad���n� kontrol etmeliyiz
		start= willBeAdded;
		printf("---EKLENDI---\n");
	}
	else {//E�er bu eklenecek ilk d���m de�ilse, son d���m� bulmal�y�z
		
		struct node * temp = start;//Listede ola��m i�in ge�ici i�aret�i
		
		while (temp->next !=NULL){//Bu d�ng� sonucunda bize son d���m� verir
			temp= temp->next;
		}
		
		willBeAdded->prev = temp;//Yeni d���m�n �nceki i�aret�isine buldu�umuz son d���m� atar�z
		temp->next= willBeAdded;//Buldu�umuz son d���m�n sonraki i�aret�isine de yeni d���m� atar�z
		printf("---EKLENDI---\n");
		
	}
	system ("pause");
	system ("cls");
}

struct node* searchNode (int sdata){//Bu fonksiyon d���m arar ("sdata" search data yani aranacak veridir)
    if (start==NULL){//Listenin dolulu�unu kontrol etmemiz gerekli
		system ("cls");
		printf("Liste Bos\n");
		system ("pause");
		system ("cls");
		return;
	}
	struct node * temp = start;//Listede ola��m i�in ge�ici i�aret�i
	while (temp->next != NULL){
		if (temp->data == sdata){//Bu d�ng� son d���me kadar kontrol eder ama son d���m bu aramaya dahil de�ildir
			system("cls");
			printf("---Dugum Bulundu: %d---\n",temp->data);
			system("pause");
			system ("cls");
			return (temp);
		}
		temp= temp->next;
	}
	if (temp->data== sdata){//Son d���m� kontrol ederiz
		    system("cls");
			printf("---Dugum Bulundu: %d---\n",temp->data);
			system("pause");
			system ("cls");
			return (temp);
	}
	printf("\nVeri Listelenmemis!!\n");
	system("pause");
	system ("cls");
}

void insertion (int sdata,int idata){//Araya ekleme fonksiyou (girilen de�erin �ncesine) ("sdata" search data yani aranacak veridir)

    struct node * temp = start;//Arama i�in ge�ici i�aret�i
    struct node * willBeAdded= makenode (idata);//D���m olu�turup atad�k ("willBeAdded" eklenecek d���m anlam�nda)
    struct node * previousNode= NULL;//Araya ekleme i�in gerekli ge�ici i�aret�i ("previousNode" �nceki d���m anlam�nda)
    
	temp= searchNode (sdata);
    previousNode= temp->prev;
	
	if (previousNode==NULL){//Kullan�c�n�n ilk d���m�n �ncesine ekleme yapmaya �al���p �al��mad���n� kontrol etmeliyiz.
		addToFirst(idata);
	}
	else{// e�er ilk d���m de�ilse devam edebiliriz
    temp->prev= willBeAdded;
    willBeAdded->next = temp;
    willBeAdded->prev= previousNode;
    previousNode->next = willBeAdded;
	}
	printf("---%d den Once Araya %d Eklendi---\n",temp->data,idata);
	system ("pause");
	system ("cls");
}

void deleteNode (int sdata){//Bu fonksiyon d���m siler
	if (start==NULL){//Listenin dolulu�unu kontrol etmemiz gerekli
		system ("cls");
		printf("Liste Bos\n");
		system ("pause");
		system ("cls");
	}
	else {
	struct node * temp = NULL;//Arama i�in ge�ici i�aret�i
	temp = searchNode(sdata);
	if (temp==NULL){}//Listede aranan verinin bulunmama ihtimali
	else{
	struct node * nextNode = temp->next;//Silme i�lemi i�in i�aret�i ("nextNode" sonraki d���m anlam�nda)
	struct node * previousNode = temp->prev;//Silme i�lemi i�in i�aret�i ("previousNode" �nceki d���m anlam�nda)
	   if (previousNode==NULL && nextNode==NULL){//Listede 1 veri olma ihtimalini kontrol etmeliyiz
		free(start);
	   	start= NULL;	
	   }
	   else if (previousNode==NULL){//Kullan�c�n�n ilk d���m� silmek isteyip istemedi�ini kontrol etmeliyiz
	    struct node * secondNode = temp->next;//Listedeki 2. D���m
		free(temp);
		secondNode->prev= NULL;
		start= secondNode;	
	   }
	   else if (nextNode==NULL){//Kullan�c�n�n son d���m� silmek isteyip istemedi�ini kontrol etmeliyiz
	    free(temp);
	    previousNode->next= NULL;
	   }
	   else{
	    free(temp);
	    previousNode->next = nextNode;
     	nextNode->prev = previousNode;
     }
	printf("---Silindi!!!---\n"),
    system ("pause");
    system ("cls");
    }
 }
}

void printNode (void){//Bu fonksiyon listeyi ekrana yazd�r�r
	
	struct node * temp = start;//Listede ola��m i�in ge�ici i�aret�i
	system("cls");
	printf ("Liste:\n\n");
	while (temp !=NULL){//Yazd�rma d�ng�s�
		printf ("%d\n",temp->data);
		temp= temp->next;
	}
	printf("\n");
	system ("pause");
	system ("cls");
}

int main(void){
	
	int i,choice,data,sdata;
	//selection screen
	while (1){
		printf("[1] Basa Ekleme\n[2] Sona Ekleme\n[3] Araya Ekleme\n[4] Veri Silme\n[5] Listeyi Yazdir\n[6] Veri Ara\n");
		printf("\nLutfen Seciminizi Yapin: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				system ("cls");
				printf("Veri Giriniz: ");
				scanf("%d",&data);
				addToFirst(data);
				break;
			case 2:
				system ("cls");
				printf("Veri Giriniz: ");
				scanf("%d",&data);
				addToLast(data);
				break;
			case 3:
				system ("cls");
				printf("Oncesine ekleme yapmak istediginiz veriyi giriniz: ");
				scanf("%d",&sdata);
				printf("\n");
				printf("Veri Giriniz: ");
				scanf("%d",&data);
				insertion(sdata,data);
				break;
			case 4:
				system ("cls");
				printf ("Silinmesiniz istediginiz veriyi giriniz: ");
				scanf("%d",&sdata);
				deleteNode(sdata);
				break;
			case 5:
				printNode();
				break;
			case 6:
				system ("cls");
				printf("Aranacak Veriyi Giriniz: ");
				scanf("%d",&sdata);
				searchNode(sdata);
				break;
		}
	}
}
