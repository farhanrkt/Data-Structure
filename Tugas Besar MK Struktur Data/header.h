#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <string>
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
using namespace std;

typedef struct elm_penulis *adr_penulis;
typedef struct elm_novel *adr_novel;

struct elm_novel
{
    string judul;
    string penulis;
    string collab;
    int tahunRilis;
    bool terhubungPenulis;
    bool terhubungCollab;
    adr_novel next;
};

struct novel {
    adr_novel first;
};

struct elm_penulis
{
    string nama;
    string tempatTanggalLahir;
    adr_penulis next;
    adr_penulis prev;
    novel list_novel;
};

struct penulis
{
    adr_penulis first;
    adr_penulis last;
};



adr_penulis create_penulis(string nama, string ttl);
adr_novel create_novel(string judul, string artis, string collab, int tahun_rilis);
void create_listpenulis(penulis &M);
void create_listnovel(novel &L);

void insert_penulis(penulis &M, novel &L, adr_penulis P);
void delete_penulis(penulis &M, string nama);
void show_penulis(penulis M);
adr_penulis find_penulis(penulis M, string nama);

void insert_novel(novel &L, adr_novel P);
void delete_novel(novel &L, string judul);
adr_novel find_novel(novel L, string judul);
void add_novel_to_penulis(penulis &M, novel &L, string nama, string judul);
void del_novel_from_penulis(penulis &M, novel &L, string nama, string judul);
void show_novel(penulis M, string nama);
void show_all_novel(novel L);

void del_penulis(penulis &M, string nama);
void del_novel(penulis &M, novel &L, string judul);

int menu();

void show_semua_penulis_dengan_novelnya(penulis M);
void show_judul_by_dua_penulis(novel L);

#endif // HEADER_H_INCLUDED
