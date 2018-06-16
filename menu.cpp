#include"playlist.h"
#include<iostream>
#include<iomanip>

using namespace std;
char getChar();
int getInt();

int main(){

Playlist library;
bool flag = true; 
char x, genre;
Style style;
int size;

 while(flag){
	
	char *title  = new char[36];
	char *artist = new char[21];
	bool y = true;
	bool a = true;

        cout<<"\nSelect an option from the following menu:\n";
        library.Menu();
	
	x = getChar();
	cin.clear();
	switch(x){
               case 'A':
               case 'a':
                cout << "Enter the title: ";
		cin.getline( title, 36, '\n');
		cout<< "\nEnter the Artist: ";
		cin.getline( artist, 21,'\n');
		cout<< "\nEnter the genre ([P]op, [R]ock, [A]lternative, [C]ountry, [H]iphop, parod[Y]): ";
		genre = getChar();

		while(y){
			if( genre == 'P' || genre == 'p'){ style = POP, y = false;}
                	else if( genre == 'R' || genre == 'r') {style = ROCK; y = false;}
                	else if( genre == 'A' || genre == 'a') {style = ALTERNATIVE;y = false;}
                	else if( genre == 'C' || genre == 'c') {style = COUNTRY;y = false;}
                	else if( genre == 'H' || genre == 'h') {style = HIPHOP; y = false;}
                	else if( genre == 'Y' || genre == 'y') {style = PARODY; y =false;}
                	else { cout<< "Invalid genre, please try again.\n"; genre = getChar(); cout<<endl;}}
                
		cout<< "\nEnter the size of the file: ";
                size = getInt();

		if (size < 0){
			while(a){
				cout<< "Size of file must be a positive value. Please try again.\n";
				size = getInt();
				cout<<endl;
				if (size > 0) a = false;}}
		
		library.Addsong(title,artist,style,size); 
                delete [] title;
		delete [] artist;
		break;

               case 'D':
               case 'd':
		cout<< "\nEnter title of song you would like to remove: ";
		cin.clear();
		cin.getline(title, 36, '\n');
                library.Removesong(title);
                break;

               case 'F':
               case 'f':
		cout<< "Search by title or by author: ";
		cin.getline(title, 36);
		library.Find(title);
		delete [] title;
                break;

               case 'S':
               case 's':
                library.Show();
                break;

		case 'C':
		case 'c':
		 cout<< "\nEnter the genre ([P]op, [R]ock, [A]lternative, [C]ountry, [H]iphop, parod[Y]): ";
                genre = getChar();
                while(y){
                        if( genre == 'P' || genre == 'p'){ style = POP, y = false;}
                        else if( genre == 'R' || genre == 'r') {style = ROCK; y = false;}
                        else if( genre == 'A' || genre == 'a') {style = ALTERNATIVE;y = false;}
                        else if( genre == 'C' || genre == 'c') {style = COUNTRY;y = false;}
                        else if( genre == 'H' || genre == 'h') {style = HIPHOP; y = false;}
                        else if( genre == 'Y' || genre == 'y') {style = PARODY; y =false;}
                        else { cout<< "Invalid genre, please try again.\n"; genre = getChar(); cout<<endl;}}
		library.ShowCategory(style);
		 break;

		case 'Z':
		case 'z':
		 cout<< library.Showsize()<<" KB\n";
		 break;
		
		case 'M':
		case 'm':
		 library.Menu();
		 break;
                
		case 'O':
		case 'o':
		 
		 cout << "Would you like to sort by Title or Artist (A or T)?";
		 x = getChar();
		 library.Sort(x);
		 break;
		case 'x':
                case 'X':
                flag = false;
                break;

		default:
		 cout<<"'"<< x << "' is not an option. ";
		 break; 
}}}

char getChar(){
 char x;
 cin >> x;
 while(cin.peek() != '\n'){
	cin.ignore();} cin.ignore();return x; }

int getInt(){
 int x;
 cin >> x;
 while(cin.peek() != '\n'){
	cin.ignore();} cin.ignore();return x;}
