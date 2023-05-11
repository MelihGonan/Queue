#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Dugum yapisi tanimi
struct node{
	
	int data;
	struct node *next;
};

// ilk ve son isaretciler
struct node *front=NULL;
struct node *rear=NULL;

// Kuyruga ekleme fonksiyonu
void Enqueue(int data){
	
	// Kuyruk bos ise
	if(front==NULL){
		struct node *New=(struct node *)malloc(sizeof(struct node));
		New->data=data;
		New->next=NULL;
		front=New;
		rear=New;
	}
	
	// Kuyruk dolu ise
	else{
		
		struct node *New=(struct node *)malloc(sizeof(struct node));
		New->data=data;
		New->next=NULL;
		rear->next=New;
		rear=New;
		
	}
}

// Kuyruktan silme fonksiyonu
void Dequeue(){
	
	if(front==NULL)
		printf("kuyruk bos");
		
	else{
		struct node *temp=front;
		front=front->next;
		free(temp);
	}
}

// Kuyrugu goruntuleme fonksiyonu
void printqueue(){
	
	// Kuyruk bos ise
	if(front==NULL){
	
		printf("Kuyruk bos");
	}
		
	// Kuyruk dolu ise	
	else{
		
		struct node *temp=front;
		while(temp!=NULL){
			
			printf("%d-> ",temp->data);
			temp=temp->next;
			
		}
		printf("\n");
	}	
}




int main(int argc, char *argv[]) {
	
	int islem=0;
	int sayi;
	
	
	while(islem!=4){
		
		printf("\nLutfen bir islem seciniz\n");
			printf("1. Ekleme\n2. Silme\n3. Goruntuleme\n4. Cikis\n");
			printf("\nSeciminiz: ");
			scanf("%d",&islem);
			
		// islem secimi	
		switch(islem){
			
			// Ekleme
			case 1:
				
				printf("\nEklemek istediginiz sayiyi giriniz: ");
				scanf("%d",&sayi);
				Enqueue(sayi);
				printf("\nBasariyla eklenmistir.\n");
				break;
			
			// Silme
			case 2:
				
				printf("\nBasariyla silinmistir.\n");	
				Dequeue();
			    break;
			
			// Goruntuleme
			case 3:
				
				printf("\nKuyruk yapisi:\n\n");
				printqueue();
				break;
			
			// Cikma
			case 4:
				break;
		}
	}
	
	
	return 0;
}
