#include <iostream>
#include <iterator>
#include <map>
#include <string>

using namespace std;

void fun(const int n, string divicenames[]) {


    map<string, int> mapa;
    mapa.insert(pair<string, int>(divicenames[0], 1));

    for (int i = 1; i < n; i++) {
        
        map<string, int>::iterator itr;
        for (itr = mapa.begin(); itr != mapa.end(); ++itr) {

            if (divicenames[i] == itr->first) {
                itr->second++;
                divicenames[i] = divicenames[i] + std::to_string(itr->second);
                break;
            }
        }
        mapa.insert(pair<string, int>(divicenames[i], 1)); 
    }
}

int main()
{
    
    const int n = 6;
    string divicenames[n] = { "switch","tv","switch","tv","switch","tv", };

    
    
    fun(n, divicenames);

    for (int i = 0; i < n; i++) {
        cout << divicenames[i] << endl;
    }

}
