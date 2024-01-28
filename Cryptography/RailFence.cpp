#include <bits/stdc++.h>
using namespace std;

string encrypt(string message) {
  float n = message.length();
  int m = ceil(n/2);

  char railFence[2][m];
  int i = 0;
  for (int col = 0; col < m; col++) {
    for (int row = 0; row < 2; row++) {
      railFence[row][col] = message[i];
      i++;
    }
  }

  string encryptedMessage = "";
  
  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < m; col++) {
      encryptedMessage += railFence[row][col];
    }
  }

  return encryptedMessage;
}

string decrypt(string encryptedMessage) {
  float n = encryptedMessage.length();
  int m = ceil(n/2);

  char railFence[2][m];
  int i = 0;
  for (int row = 0; row < 2; row++) {
    for (int col = 0; col < m; col++) {
      railFence[row][col] = encryptedMessage[i];
      i++;
    }
  }

  string decryptedMessage = "";
  
  for (int col = 0; col < m; col++) {
    for (int row = 0; row < 2; row++) {
      decryptedMessage += railFence[row][col];
    }
  }

  return decryptedMessage;
}

int main() {
  string message;
  cout << "Message: ";
  cin >> message;

  string encryptedMessage = encrypt(message);
  cout << "Encrypted Message: " << encryptedMessage << endl;
  cout << "Decrypted Message: " << decrypt(encryptedMessage) << endl;

  return 0;
}