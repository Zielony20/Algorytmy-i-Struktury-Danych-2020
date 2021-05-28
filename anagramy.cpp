#include <iostream>
#include <iterator>
#include <map>
#include <string>

using namespace std;

int* fun(const int n, string ana1[], string ana2[]) {

    int* resault = new int[n];

    for (int i = 0; i < n; i++) {
        
        if (ana1[i].length() != ana2[i].length()) {
            resault[i] = -1;
        }
        else {
            int len = ana1[i].length();
            resault[i] = 0;
            for (int j = 0; j < len; j++)
            {
                if (ana1[i][j] != ana2[i][len-j-1]) {
                    resault[i]++;
                }
            }
            
        }
      
    }
    return resault; 
}

int main()
{
    
    const int n = 6;
    string a1[n] = { "tea","toe","act","tv","switch","tv", };
    string a2[n] = { "aet","tea","acts","tv","switch","tv", };

    int* r = fun(n, a1,a2);
    for (int i = 0; i < n; i++) {
        cout << r[i] << endl;
    }
}
