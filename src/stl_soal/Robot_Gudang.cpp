#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), c(n);

    for (int i = 0; i < n; i++){
        cin >> x[i];}
    for (int i = 0; i < n; i++){
        cin >> c[i];}

    // 1. gabungkan koordinat dan kategori
    // 2. urut dari koordinat 
    vector<pair<int,int>> paket(n);
    for (int i = 0; i < n; i++) {
        paket[i] = {x[i], c[i]};
    }
    sort(paket.begin(), paket.end()); // sort 

    // track category yg udah di ambil
    map<int, bool> kategori_diambil;
    int jumlah = 0;

    for (int i = 0; i < n; i++) {
        int kategori = paket[i].second;

        // untuk category belum pernah di ambil
        if (kategori_diambil.find(kategori) == kategori_diambil.end()) {
            kategori_diambil[kategori] = true;
            jumlah++;
        }
    }

    cout << jumlah << endl;

    return 0;
}