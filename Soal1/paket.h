#ifndef PAKET_H
#define PAKET_H

#include <string>

struct Paket {
    std::string kode;   // satu kata, 1-10 karakter
    int berat;          // 1-5000 gram
};

struct Node {
    Paket info;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
};

struct Statistik {
    int terkirim;       // jumlah paket terkirim
    long totalBerat;    // total berat terkirim (gram)
};

void createQueue(Queue& q);
bool isEmptyQueue(const Queue& q);

Node* alokasi(const std::string& kode, int berat);   // nullptr jika gagal
void dealokasi(Node*& p);                            // delete + p = nullptr

void enqueue(Queue& q, Node* p);                     // p sudah dialokasikan
Node* dequeue(Queue& q);                             // melepas node depan, TANPA delete

Node* findElm(const Queue& q, const std::string& kode);
bool fFindElm(const Queue& q, const Node* p);        // cek keanggotaan berdasarkan alamat
int nbList(const Queue& q);
void printInfo(const Queue& q);
void delAll(Queue& q);

// fungsi bantu
int posisiElm(const Queue& q, const std::string& kode);  // mulai dari 1, 0 jika tidak ada
long totalBerat(const Queue& q);

#endif
