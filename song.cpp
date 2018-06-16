#include"song.h"
#include<cstring>
#include<iomanip>
using namespace std;

Song::Song(){
  size = 0;
  strcpy(title," ");
  strcpy(artist, " ");}

void Song::Set(const char *t, const char *a, Style st, int sz){
 strcpy( title, t );
 strcpy( artist , a);
 category = st;
 size = sz; } 

const char* Song::GetTitle() const{
 return title;}

const char* Song::GetArtist() const{
 return artist;}

int Song::GetSize()const{
 return size;}

Style Song::GetCategory() const{
 return category;}

ostream& operator<<(ostream &os, const Song &s){
 for(int i = 0; s.title[i] != '\0'; i++){
	os <<s.title[i];}
 for (int i =1, a = 38 - strlen(s.title); i < a; i++) cout<<" ";
 for(int i = 0; s.artist[i] != '\0'; i++){
	os << s.artist[i];}
	 double mb = s.size / 1000.;

 switch(s.category){
	case POP:
	 os << setw(25- strlen(s.artist)) << "Pop";
	 os << setw( 16 ) << setprecision(1)<< fixed << mb<<endl;
	 break;
	case ROCK:
	 os<< setw(26- strlen(s.artist)) << "Rock";
	 os<< setw(15) << setprecision(1)<< fixed << mb<<endl;
	 break;
	case ALTERNATIVE:
	 os<< setw(33- strlen(s.artist)) << "Alternative";
	 os<< setw(8) << setprecision(1)<< fixed << mb<<endl;
	 break;
	case COUNTRY:
	 os<< setw(29 - strlen(s.artist)) << "Country";
	 os<< setw(12) << setprecision(1)<< fixed << mb<<endl;
	 break;
	case HIPHOP: 
	 os<< setw(28- strlen(s.artist)) << "HipHop";
	 os<< setw(13) << setprecision(1)<<fixed << mb<<endl;
	break;
	case PARODY:
	 os<<setw(28- strlen(s.artist)) << "Parody";
	 os<<setw(13) << setprecision(1)<<fixed << mb<<endl;
	 break;}

 
return os;}



