// SERIAL VERSION OF 1 THREAD
// CASINO PROJECT
// COMP262 - Robert Trujillo & Jose Cahue

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


using namespace std;

// Function Definition to fill array with random number
void randFunc(int *array1, int size){
    
    for(int i=0;i<size;i++){
        array1[i]=rand()%(6+1-1)+1;
    }
    
}

void displayHand(int *array1, int size){
    cout<<"Your Hand"<<endl;
    for(int i=0;i<size;i++){
        cout<<array1[i]<<" ";
    }
}

void storeHand(int *array1,int size, int *count){
    for(int i=0;i<size;i++){
        count[array1[i]]++;
    }
    
}

void diplayStoreHand(int *count){
    cout<<"Display Store Hand"<<endl;
    for(int i=0;i<7;i++){
        cout<<count[i];
    }
}

void determainHand(int *count,int ppair,int three, int four, int five,int fullHouse, int twoPair, int nothing){
    
    int nCount=0;
    
    for(int i=1;i<=6;i++){
        if(count[i]==5) five++;
        else if(count[i]==4) four++;
        else if(count[i]==3) three++;
        else if(count[i]==2) ppair++;
        else if((count[i]==1)||(count[i]==0)) nCount++;
    }
    
    if(nCount==6)nothing++;
    
    if((three==1)&&(ppair==1)){
        fullHouse++;
        three--;
        ppair--;
    }
    if(ppair==2){
        twoPair++;
        ppair-=2;
    }
    
    cout<<" "<<endl;
    cout<<"pair:"<<ppair<<endl;
    cout<<"three:"<<three<<endl;
    cout<<"four:"<<four<<endl;
    cout<<"five:"<<five<<endl;
    cout<<"fullHouse:"<<fullHouse<<endl;
    cout<<"twoPair:"<<twoPair<<endl;
    cout<<"nothing:"<<nothing<<endl;
    cout<<" "<<endl;
    
}



int main(){
    //#pragma omp parallel sections
    {
        time_t t;
        srand((unsigned) time(&t));
    
        int array1[5];
        int count[7]={0,0,0,0,0,0,0};
        //int dCount[7]={0,1,1,1,0,0,1};
        int size=5;
        int ppair=0;
        int three=0;
        int four=0;
        int five=0;
        int nothing=0;
        int fullHouse=0;
        int twoPair=0;
    
        //#pragma omp section
        randFunc(array1,size);
        displayHand(array1, size);
        cout<<" "<<endl;
        storeHand(array1,size,count);
        //diplayStoreHand(count);
        //#pragma omp section
        determainHand(count,ppair,three,four,five,fullHouse,twoPair,nothing);
    }
    return 0;
}