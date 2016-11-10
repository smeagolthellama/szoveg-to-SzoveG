#include <iostream>
#include <fstream>
#include "karlanc.hpp"

using namespace std;

void feldolgoz(ifstream& f, ofstream& g);

int main()
{
	ifstream f("szoveg.txt");
	ofstream g("szoveg.ki");
	feldolgoz(f, g);
	return 0;
}

void feldolgoz(ifstream& f, ofstream& g)
{
	int len;
	int i;
	char szk[CHAR_STAR_SIZE][CHAR_STAR_SIZE];
	char c[CHAR_STAR_SIZE];
	cout << "In feldogoz\n";
	while(!f.eof()) {
		f.getline(c, CHAR_STAR_SIZE);
		cout<<hossz(c)<<endl;

		if(hossz(c) > 0) {
			cout << "calling szavak\n";
			len = szavak( c, szk); // restart szavak with 1 word/line, overwriting whats there??
			cout<<len;
			for(i = 0; i < len; i++) {
				int h=hossz(szk[i]);
				if (h) {
					cout << szk[i] << endl;
					szk[i][0] -= 32;
					if(h>1){
						szk[i][h - 1] -= 32;
					}
					cout << szk[i] << endl;
				}
			}

			for(i = 0; i < len; i++) {
				for(int j = 0; j < hossz(szk[i]); j++) {
					g << szk[i][j] /*<< ' ' << (unsigned short int) szk[i][j] << ' '*/;
					cout<<szk[i][j];
				}
				cout<<endl;
				g << endl;
			}
		}
	}
}
