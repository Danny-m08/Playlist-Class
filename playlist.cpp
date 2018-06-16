#include"playlist.h"
#include<cstring>
#include<iomanip>
using namespace std;

Playlist::Playlist(){
 library = new Song[5];
 filledslots = 0;
 slots = 5;}


Playlist::~Playlist(){
delete [] library;}


void Playlist::expand(){
 slots += 5;
 cout << "Array is being resized...  The new size is: " << slots << endl;

 Song *temp = new Song[ slots ];
 for (int i = 0; i < filledslots; i++){ temp[i].Set(library[i].GetTitle(),library[i].GetArtist(), library[i].GetCategory(), library[i].GetSize());} 
 delete [] library;
library = temp;}

void Playlist::contract(int a){
 slots = slots - a;
 cout<< "Array is being resized... The new size is: "<< slots << endl;		
 Song *temp = new Song[slots];
 for (int i = 0; i < filledslots; i++) temp[i].Set(library[i].GetTitle(),library[i].GetArtist(), library[i].GetCategory(), library[i].GetSize());
 delete [] library;
library = temp;}



void Playlist::Addsong( char *s, char *a, Style c, int size){
 if ( filledslots == slots ) expand();
 library[filledslots].Set(s,a,c,size);
 filledslots++;}

 
void Playlist::Removesong(const char *search){
 if( filledslots == 0 ) {
	cout << "No books to remove.\n";
	return;}
 int count=0;
 for( int i = 0; i < filledslots; i++){
	if ( strcmp( search, library[i].GetTitle()) == 0 )count++;}

 if (count == 0){ 
	cout<< "We did not find a title that matched your search.\n";
	return;}

 if ( slots - filledslots + count > 5 ) contract (slots-filledslots+count-5);
 Song *temp = new Song[slots];
 for (int i = 0, a = 0; i < filledslots; a++,i++){
	if ( strcmp( search, library[a].GetTitle()) == 0){
		i--;
		continue;}
	else temp[i].Set(library[a].GetTitle(),library[a].GetArtist(),library[a].GetCategory(),library[a].GetSize());}
 	
 delete [] library;
 filledslots = filledslots - count;
 library = temp;
}

void Playlist::Show()const{
 if(filledslots == 0 ) {cout<< "There are no books to show.\n"; return;}
 cout<< "Title" << setw(38) << "Artist" << setw(21) << "Style" << setw(18) << "Size (MB)\n\n";
 for (int i = 0; i < filledslots; i++){ cout << library[i];}
cout<<endl;
 if (filledslots == 1) cout<< "There is 1 song in this playlist.";
 else cout << "There are " << filledslots << " songs in this playlist.";
 cout << "\nThis playlist takes up " << setprecision(2)<<fixed<< Showsize()/1000. << " MB\n"; 
}

double Playlist::Showsize()const{
 double sum=0;
 for(int i = 0; i < filledslots; i++){sum = sum + library[i].GetSize();}
 return sum;}

void Playlist::Menu()const{
cout<< "\nA:	Add a song to the playlist\n" 
	<<"F:	Find a song on the playlist\n"
	<<"D:	Delete song from the playlist\n"
	<<"S:	Show the entire playlist\n"
	<<"C:	Category summary\n" 
	<<"Z:	Show playlist size\n"
	<<"M:	Show this menu\n"
	<<"O:	Sort playlist\n"
	<<"X:	Exit the program\n";}


	
void Playlist::Find(const char *search)const{
 
 int count = 0;
		for ( int i = 0 ; i < filledslots; i++){if( strcmp(search, library[i].GetTitle()) == 0){
	cout<< "\nTitles that matched your search:\n";count++; break;}}
 
 if (count == 1){ cout<< "Title" << setw(38)<< "Artist"<< setw(21)
		<< "Style"<< setw(18) << "Size (MB)\n\n";
 		for (int i = 0; i < filledslots; i++){
			if(strcmp( search, library[i].GetTitle()) == 0) cout << library[i];}}
 int a = count;
 
 for (int i = 0, count = 0; i < filledslots; i++){ if (strcmp(search,library[i].GetArtist()) == 0)
	cout<< "\n\nArtists that matched your search:\n"; count++; break;
 if( i == 1){cout<< "Title" << setw(38) << "Artist" << setw(21)
		<< "Style" << setw(18) << "Size (MB)\n\n";
	 	for (int i = 0; i < filledslots; i++){
                if(strcmp( search, library[i].GetArtist()) == 0) cout << library[i];}}}
 if ( count == 0 && a == 0 ) {cout << "No titles or arists matched your search\n";}
 return;
}

void Playlist::Sort(const char x){
 bool flag = true;
 Song min;
 Song *temp = new Song[slots];
int filled = filledslots, slot = slots;
 
 if ( x == 't' || 'T' ){
 	int a = 0;
	while(filledslots != 1){
	min.Set(library[0].GetTitle(),library[0].GetArtist(),library[0].GetCategory(),library[0].GetSize());	
		for(int i =1; i < filledslots; i++){
			if( strcmp(min.GetTitle(), library[i].GetTitle()) > 0) min.Set(library[i].GetTitle(),library[i].GetArtist(), library[i].GetCategory(),library[i].GetSize());}
	temp[a].Set(min.GetTitle(),min.GetArtist(),min.GetCategory(),min.GetSize());
	Removesong(min.GetTitle());a++;}
 	temp[filled-1].Set(library[0].GetTitle(),library[0].GetArtist(),library[0].GetCategory(),library[0].GetSize());}

 else if ( x == 'a' || x== 'A' ){
        int a = 0; 
	while( filledslots != 1){
		min.Set(library[0].GetTitle(),library[0].GetArtist(),library[0].GetCategory(),library[0].GetSize());
                	for(int i =1; i < filledslots; i++){
                        	if( strcmp(min.GetArtist(), library[i].GetArtist()) > 0) min.Set(library[i].GetTitle(),library[i].GetArtist(),
                        	library[i].GetCategory(),library[i].GetSize());}
        	temp[a].Set(min.GetTitle(),min.GetArtist(),min.GetCategory(),min.GetSize());
        	Removesong(min.GetTitle()); a++;}
	 temp[filled-1].Set(library[0].GetTitle(),library[0].GetArtist(),library[0].GetCategory(),library[0].GetSize());}
 filledslots = filled; slots = slot;
 delete [] library;
 library = temp;}

void Playlist::ShowCategory(const Style genre)const{
 if( filledslots == 0) {cout<< "There are no songs in your library.\n"; return;}
 int count = 0;
for (int i = 0; i < filledslots; i++){
	if ( genre == library[i].GetCategory()) {cout<<library[i]; count ++;}}
 if(count == 0) cout<< "There are no songs in your library with this genre.\n";}
