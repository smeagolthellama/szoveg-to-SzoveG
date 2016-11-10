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
	char szavak[CHAR_STAR_SIZE][CHAR_STAR_SIZE];
	char c[CHAR_STAR_SIZE];

	while(!f.eof()) {
		f.getline(c, CHAR_STAR_SIZE);
		cout<<hossz(c);

		if(hossz(c) > 0) {
			szavakrabont(len, c, szavak); // restart szavak with 1 word/line, overwriting whats there??

			for(i = 0; i < len; i++) {
				int h=hossz(szavak[i]);
				if (h) {
					cout << szavak[i] << endl;
					szavak[i][0] -= 32;
					if(h>1){
						szavak[i][h - 1] -= 32;
					}
					cout << szavak[i] << endl;
				}
			}

			for(i = 0; i < len; i++) {
				for(int j = 0; j < hossz(szavak[i]); j++) {
					g << szavak[i][j] /*<< ' ' << (unsigned short int) szavak[i][j] << ' '*/;
					cout<<szavak[i][j];
				}
				cout<<endl;
				g << endl;
			}
		}
	}
}
