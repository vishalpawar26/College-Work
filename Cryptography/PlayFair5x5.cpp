#include <bits/stdc++.h>
using namespace std;

class PlayFair {
    private:
    string removeDuplicates(string str) {
        string alpha = str + "abcdefghiklmnopqrstuvwxyz";

        int n = alpha.length();

        string s = "";
        s += alpha[0];
        for (int i = 1; i < n; i++) {
            if (s.find(alpha[i]) == string::npos) {
                s += alpha[i];
            }
        }

        return s;
    }

    vector<string> splitArray(string text) {
        int n = text.length();
        vector<string> arr;    

        for (int i = 0; i < n; i+=2) {
            arr.push_back(text.substr(i, 2));
        }

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].length() == 1) {
                arr[i] += 'x';
            }
            if (arr[i][0] == arr[i][1]) {
                arr[i][1] = 'x';
            }
        }

        return arr;
    }

    vector<vector<char>> genMatrix(string text) {
        int n = 5;
        string matData = removeDuplicates(text);

        int ind = 0;
        vector<vector<char>> mat(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = matData[ind];
                ind++;
            }
        }

        return mat;
    }

    pair<int, int> search(char c, vector<vector<char>> mat) {
        pair<int, int> index;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (c == mat[i][j]) {
                    index.first = i;
                    index.second = j;
                }
            }
        }

        return index;
    }

    int mod5(int n) {
        if (n < 5) {
            n += 5;
        }

        return n%5;
    }

    string genText(vector<string> arr) {
        string text = "";
        for (int i = 0; i < arr.size(); i++) {
            text += arr[i];
        }

        return text;
    }

    string decrypt(string cipherText, string key) {
        vector<string> arr = splitArray(cipherText);

        int n = 5;
        vector<vector<char>> mat(n, vector<char>(n));
        mat = genMatrix(key);

        for (int i = 0; i < arr.size(); i++) {
            pair<int, int> fInd = search(arr[i][0], mat);
            pair<int, int> sInd = search(arr[i][1], mat);

            if (fInd.second == sInd.second) {
                arr[i][0] = mat[mod5(fInd.first - 1)][fInd.second];
                arr[i][1] = mat[mod5(sInd.first - 1)][sInd.second];
            }
            else if (fInd.first == sInd.first) {
                arr[i][0] = mat[fInd.first][mod5(fInd.second - 1)];
                arr[i][1] = mat[sInd.first][mod5(sInd.second - 1)];
            }
            else {
                arr[i][0] = mat[fInd.first][sInd.second];
                arr[i][1] = mat[sInd.first][fInd.second];
            }
        }

        return genText(arr);
    }

    string encrypt(string plainText, string key) {
        vector<string> arr = splitArray(plainText);

        int n = 5;
        vector<vector<char>> mat(n, vector<char>(n));
        mat = genMatrix(key);

        for (int i = 0; i < arr.size(); i++) {         
            pair<int, int> fInd = search(arr[i][0], mat);
            pair<int, int> sInd = search(arr[i][1], mat);

            if (fInd.second == sInd.second) {
                arr[i][0] = mat[mod5(fInd.first + 1)][fInd.second];
                arr[i][1] = mat[mod5(sInd.first + 1)][sInd.second];
            }
            else if (fInd.first == sInd.first) {
                arr[i][0] = mat[fInd.first][mod5(fInd.second + 1)];
                arr[i][1] = mat[sInd.first][mod5(sInd.second + 1)];
            }
            else {
                arr[i][0] = mat[fInd.first][sInd.second];
                arr[i][1] = mat[sInd.first][fInd.second];
            }
        }

        return genText(arr);
    }
    
    public:
    void playFairCipher(string plainText, string key) {
        string cipherText = encrypt(plainText, key);
        string decryptedText = decrypt(cipherText, key);

        cout << "Plain Text: " << plainText << endl;
        cout << "Cipher Text: " <<  cipherText << endl;
        cout << "Decrypted Text: " << decryptedText << endl;
    }
};

int main() {
    string plainText = "maytheforcebewithyou";
    string key = "lightsaber";

    PlayFair obj;
    obj.playFairCipher(plainText, key);

    return 0;
}