#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


struct arc{
int nod1;
int nod2;
char c;
};

bool stringCheck(int start, string word, int tr, arc trz[], int nEndStates, int endStates[] ){
 char k; //Prima litera
 int i; //Contor
 int nodCurent = start;
 while (!word.empty()){
        k = word[0];
        for (i=0; i<tr; i++){
            if ((trz[i].nod1 == nodCurent) && (trz[i].c == k)){
                word.erase(0,1);
                nodCurent = trz[i].nod2;
                break;
            }
        }
 }
 for (i=0; i<nEndStates; i++)
    if (nodCurent == endStates[i])
        return 1;
 return 0;
}

int main()
{
    string alphabet;
    int nStates; // nr stari
    int nEndStates; //nr stari finale

    int start;
    int n; //nr tranzitii


    ifstream f;
    f.open("info.in");
    if (!f)
        cout << "Not valid";
    f >> alphabet;
    f >> nStates;
    f >> nEndStates;
    int endStates[nEndStates];

    int i;
    for (i=0; i<nEndStates; i++)
        f >> endStates[i];
    f >> start;
    f >> n;

    arc trz[n];
    for (i=0; i<n; i++){
        f >> trz[i].nod1 >> trz[i].nod2 >> trz[i].c;
    }
    string word;
    cin >> word;
    cout << word;
    cout << stringCheck(start, word, n, trz, nEndStates, endStates);

}
