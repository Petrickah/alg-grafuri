#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void citire(vector<int> *&la, int &nrMuchii, int &nrNoduri, istream &in) {
    int x, y;
    in>>nrNoduri>>nrMuchii;
    la = new vector<int>[nrNoduri+1];
    for(int i=0; i<nrMuchii; i++)
    {
        in>>x>>y;
        la[x].push_back(y);
        la[y].push_back(x);
    }
}

void afisare(vector<int> *la, int nrNoduri, ostream &out) {
    for(int x = 1; x<=nrNoduri; x++){
        out<<x<<": ";
        for(int y: la[x])
            out<<y<<" ";
        out<<endl;
    }
}

int viz[100], niv[100], nivMin[100], critic[100];
void df(vector<int> *la, int x, ostream& out) {
    viz[x]=1;
    nivMin[x] = niv[x];
    for(int y: la[x]){
        if(viz[y]==0){
            niv[y]=niv[x]+1;
            df(la, y, out);
            if(nivMin[y]>niv[x])
                out<<x<<" "<<y<<endl;
            if(nivMin[y]>=niv[x])
                critic[x]=1;
            nivMin[x]=(int)min(nivMin[x], nivMin[y]);
        }
        else if(niv[y]<niv[x]-1)
            nivMin[x]=(int)min(nivMin[x], niv[y]);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    vector<int> *la;
    int nrNoduri, nrMuchii;
    ifstream graf("graf.in");
    ofstream result("graf.out");
    citire(la, nrMuchii, nrNoduri, graf);
    afisare(la, nrNoduri, cout);
    result<<"Legaturi critice:\n";
    df(la, 1, result);
    result<<"Noduri vulnerabile:\n";
    for(int x=1; x<=nrNoduri; x++)
        if(critic[x]==1)
            result<<x<<" ";
    return 0;
}
