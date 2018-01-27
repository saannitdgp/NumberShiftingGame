#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define ESC 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

class NumberShiftingGame{
    public:
        /* Function Declaration*/
        int size,rsize;
        vector<vector<int> > matrix;
        int random_array[17];
        void create_matrix();
        bool check_win();
        int press_key();
        void display_matrix();
        bool move_left();
        bool move_right();
        bool move_up();
        bool move_down();
        //void display_matrix();
        void display();
        void lets_play();
        void inti();
        NumberShiftingGame(){ 
            inti();
        }       
};
/*-------------------------------------------------------------------------------*/
/*Function Definition*/
void NumberShiftingGame:: inti(){
    for(int i=0;i< 15 ; i++) random_array[i]=i+1;//created array for filling random integers
            size=4;
			rsize=14;    
			vector<int> v(4),vv;
            for(int i=0; i< 4 ;i++){
             matrix.push_back(vv);
             matrix[i].resize(4);
         }
    }
/*-------------------------------------------------------------------------------*/
void NumberShiftingGame :: display(){
            for(int i=0; i< 15 ;i++) cout<<random_array[i]<<" ";
            cout<<"\n";
}
/*-------------------------------------------------------------------------------*/
void NumberShiftingGame :: create_matrix(){
     int i,j;
    for(i=0;i< size ;i++) {
        for(j=0; j< size ; j++) {
       if(rsize >=0){
         int x=rand()%(rsize)+1;
         matrix[i][j]=random_array[x];
         random_array[x]=random_array[rsize];
         rsize--;   
        }
        else  matrix[i][j]=0;//last block
    }
}
}
/*-------------------------------------------------------------------------------*/
void NumberShiftingGame :: display_matrix(){
    cout<<"---------------------------------------\n";
    for(int i=0; i< size ; i++) {
        cout<<"|";
        for(int j=0; j< size ;j++) {
            if(matrix[i][j]!=0) printf("  %-3d  |  ", matrix[i][j]);
            else cout<<"      |     ";
        }
        cout<<"\n---------------------------------------\n";   
    }
}
/*-------------------------------------------------------------------------------*/
int NumberShiftingGame::press_key(){
    int key;
    key=getch();
    cout<<"Ascii value of key :"<<key<<"\n";
    if(key==224) key=getch();
    switch(key){
        case 27:
           return ESC;
        case 72:
           return UP;
        case 80:
           return DOWN;
        case 75:
           return LEFT;
        case 77:
           return RIGHT;
    }
}
/*-------------------------------------------------------------------------------*/
bool NumberShiftingGame::check_win(){
    int number=1;
    bool flag;
    for(int i=0 ; i< size ;i++) {
        for(int j=0 ;j< size ;j++) {
           if(matrix[i][j]!=number) {
               flag=true;
               break;
           } 
           else number++;
        }
        if(number==16) number=0; 
    }
    if(flag) return false;
    else return true;
}
/*-------------------------------------------------------------------------------*/
bool NumberShiftingGame::move_up(){
 int p,q;//first find the position of blank block
 bool zerofound=0;
 for(int i=0 ;i< size ;i++) {
 	for(int j=0; j< size ;j++) {
 		if(matrix[i][j] ==0 ) {
 			p=i;
 			q=j;
 			zerofound=1;
 			break;
		 }
	 
	 if(zerofound) break;
	 }
	 
 }
 if(p==size-1) return false;
 swap(matrix[p][q],matrix[p+1][q]);
 return true;
}
/*-------------------------------------------------------------------------------*/
bool NumberShiftingGame::move_down(){
 int p,q;//first find the position of blank block
 bool zerofound=0;
 for(int i=0 ;i< size ;i++) {
 	for(int j=0; j< size ;j++) {
 		if(matrix[i][j] ==0 ) {
 			p=i;
 			q=j;
 			zerofound=1;
 			break;
		 }
	 }
	 if(zerofound) break;
 }
 if(p==0) return false;
 swap(matrix[p][q],matrix[p-1][q]);
 return true;
}
/*-------------------------------------------------------------------------------*/
bool NumberShiftingGame::move_left(){
  int p,q;//first find the position of blank block
  bool zerofound=0;
   for(int i=0 ;i< size ;i++) {
    	for(int j=0; j< size ;j++) {
 	    	if(matrix[i][j] ==0 ) {
 			p=i;
 			q=j;
 			zerofound=1;
 			break;
		 }
	 }
	 if(zerofound) break;
 }
 if(p==size-1) return false;
 swap(matrix[p][q],matrix[p][q+1]);
 return true;
}
/*-------------------------------------------------------------------------------*/
bool NumberShiftingGame::move_right(){
  int p,q;//first find the position of blank block
  bool zerofound=0;
   for(int i=0 ;i< size ;i++) {
    	for(int j=0; j< size ;j++) {
 	    	if(matrix[i][j] ==0 ) {
 			p=i;
 			q=j;
 			zerofound=1;
 			break;
		 }
	 }
	 if(zerofound) break;
 }
 if(q==0) return false;
 swap(matrix[p][q],matrix[p][q-1]);
 return true;
}
/*-------------------------------------------------------------------------------*/
void NumberShiftingGame:: lets_play(){
    int move=100;
    while(move){
    	display_matrix();
    	//cout<<"Your Moves:"<<move<<"\n";
        if(check_win()) {
            cout<<"Congratulation you win the game :\n";
            cout<<"Your remaining moves:"<<100-move<<"\n";
            break;
        }
        switch(press_key()){
            case ESC:
                cout<<"Thanks for playing this Game:\n";
                exit(0);
            case UP:
                if(!move_up()) move++;
                break;
            case DOWN:
                if(!move_down()) move++;
                break;
            case LEFT:
                if(!move_left()) move++;
                break;
            case RIGHT:
                if(!move_right()) move++;
                break; 
            default:
            	move++;
        }
        system("cls");
        move--;
        cout<<"Hey! You have "<<move<<" numbe of moves:\n";
    }
    cout<<"Game Is Over:\n";
}
/*-------------------------------------------------------------------------------*/
int main(){
    NumberShiftingGame obj;
    obj.create_matrix();
    obj.lets_play();
    return 0;
}
