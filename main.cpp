    #include <iostream>
    #include <fstream>
    #include <string>

using namespace std;

void open_with_append(ofstream & utfil, string const & filename);
void copy(istream & in, ofstream& out);



int main() {

    ofstream utfil{"INKOP.TXT", ofstream ::app};  //Korrekt
   //ofstream utfil;
   open_with_append(utfil, "INKOP.TXT");
utfil << "Annans" << endl;

    utfil.close();

    return 0;
}

void open_with_append(ofstream & utfil, string const & filename){
    ifstream infil{filename};

    utfil.open("TMP");

    //Kopiera från inkop till TMP
    copy(infil, utfil);


    //Stäng båda filerna
    utfil.close();
    infil.close();

    //öppna för skrivning i INKOP
    utfil.open(filename);

    //Öppna för läsning i TMP
    infil.open("TMP");


    copy(infil, utfil);

    //Ta bort
    infil.close();

}
void copy(istream& in, ofstream& out){
    char c;
    for (char c; in.get(c) ;) {
        out << c;
    }
}
