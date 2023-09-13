#include "header.h"

adr_penulis create_penulis(string nama, string ttl){
    //create address penulis
    adr_penulis P = new elm_penulis;
    P->nama = nama;
    P->tempatTanggalLahir = ttl;
    P->next = NULL;
    P->list_novel.first = NULL;
    return P;
}

adr_novel create_novel(string nama, string penulis, string collab, int tahun_rilis){
    //create address novel
    adr_novel P = new elm_novel;
    P->judul = nama;
    P->penulis = penulis;
    P->collab = collab;
    P->tahunRilis = tahun_rilis;
    P->terhubungPenulis;
    P->terhubungCollab;
    P->next = NULL;

    return P;
}

void create_listpenulis(penulis &M){
    //create list penulis
    M.first = NULL;
    M.last = NULL;
}

void create_listnovel(novel &L){
    //create list novel
    L.first = NULL;
}

void insert_penulis(penulis &M, novel &L, adr_penulis P){
    //memasukkan adr penulis ke list penulis
    if(M.first == NULL && M.last == NULL) {
        M.first = P;
        M.last = P;
    } else {
        next(P) = M.first;
        prev(next(P)) = P;
        M.first = P;
    }

    adr_novel X = L.first;
    while(X != NULL) {
        if ((X->penulis == P->nama) && (X->terhubungPenulis == false)) {
            add_novel_to_penulis(M, L, P->nama, X->judul);
            X->terhubungPenulis = true;
        } else if ((X->collab == P->nama) && (X->terhubungCollab == false)) {
            add_novel_to_penulis(M, L, P->nama, X->judul);
            X->terhubungCollab = true;
        }
        X = next(X);
    }
}

void delete_penulis(penulis &M, string nama) {
    //menghapus penulis dari list
    adr_penulis P = find_penulis(M, nama);

    if (P == NULL) {
        cout << "Tidak ada penulis dengan nama tersebut" << endl;
    } else if (P == M.first) {
        if (next(P) == NULL) {
            M.first = NULL;
            M.last = NULL;
        } else {
            M.first = next(P);
            next(P) = NULL;
            P = NULL;
        }
    } else if (P == M.last) {
        M.last = prev(M.last);
        next(M.last) = NULL;
        P = NULL;
    } else {
        adr_penulis Q = M.first;
        while (next(Q) != P) {
            Q = next(Q);
        }
        next(Q) = next(P);
        prev(next(P)) = Q;
        P = NULL;
    }
}

void show_penulis(penulis M) {
    //menampilkan list penulis
    adr_penulis P = M.first;
    if(P == NULL) {
        cout << "DAFTAR PENULIS KOSONG" << endl;
    } else {
        int i = 1;
        while (P != NULL) {
            cout << "[" << i++ << "]" << endl;
            cout << "Nama penulis        : " << P->nama << endl;
            cout << "Tempat Tanggal Lahir : " << P->tempatTanggalLahir << endl;
            P = next(P);
        }
        cout << endl;
    }
}

adr_penulis find_penulis(penulis M, string nama) {
    //mencari penulis berdasarkan nama
    adr_penulis P = M.first;
    if (P == NULL) {
        return NULL;
    } else {
        if (nama == M.first->nama) {
            return M.first;
        } else if (nama == M.last->nama) {
            return M.last;
        } else {
            while (P->nama != nama) {
                P = next(P);
                if (P == NULL) {
                    return NULL;
                }
            }
            return P;
        }
    }
}

void insert_novel(novel &L, adr_novel P){
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void delete_novel(novel &L, string judul){
    //menghapus novel dari list
    adr_novel P = find_novel(L, judul);
    adr_novel Q = L.first;

    if (P == NULL) {
        cout << "Tidak ada novel dengan judul tersebut" << endl;
    } else if (P == L.first) {
        if (next(P) == NULL) {
            L.first = NULL;
        } else {
            L.first = next(P);
            next(P) = NULL;
        }
    } else if (P != L.first && next(P) == NULL) {
        while (next(Q) != P) {
            Q = next(Q);
        }
        next(Q) = NULL;
    } else {

        while (next(Q) != P) {
            Q = next(Q);
        }
        next(Q) = next(P);
        P = NULL;
    }
}

adr_novel find_novel(novel L, string judul){
    //mencari novel berdasarkan judul
    adr_novel P = L.first;

    if (P == NULL) {
        return NULL;
    } else {
        while(judul != P->judul && P != NULL) {
            P = next(P);
        }
        return P;
    }
}

void add_novel_to_penulis(penulis &M, novel &L, string nama, string judul){
    adr_penulis P = find_penulis(M, nama);
    adr_novel Q = find_novel(L, judul);

    if(P != NULL) {

        if(Q->penulis == P->nama || Q->collab == P->nama) {
            adr_novel R = create_novel(Q->judul, Q->penulis, Q->collab, Q->tahunRilis);

            insert_novel(P->list_novel, R);
        } else {
            Q->terhubungPenulis = false;
            Q->terhubungCollab = false;
        }
    } else {
        Q->terhubungPenulis = false;
        Q->terhubungCollab = false;
    }
}

void del_novel(penulis &M, novel &L, string judul){
    //delete novel di dalam list dan novel dalam semua penulis
    adr_novel P = find_novel(L, judul);

    if (P == NULL) {
        cout << "Tidak ada novel dengan judul tersebut" << endl;
    } else {
        adr_penulis X = find_penulis(M, P->penulis);
        //cout << "X : " << X << endl;
        if (X != NULL) {
            //cout << "X tidak NULL" << endl;
            delete_novel(X->list_novel, judul);
            //cout << "X selesai delete novel" << endl;
        }

        if (P->collab != "-") {
            adr_penulis Y = find_penulis(M, P->collab);
            //cout << "Y : " << Y << endl;
            if (Y != NULL) {
                //cout << "Y tidak NULL" << endl;
                delete_novel(Y->list_novel, judul);
                //cout << "Y selesai delete novel" << endl;
            }
        }
        delete_novel(L, judul);
    }
    //cout << "SELESAI PENGKONDISIAN" << endl;

}

void show_novel(penulis M, string nama) {
    //menampilkan novel berdasarkan nama penulis yang dicari
    adr_penulis P = find_penulis(M, nama);

    if (P == NULL) {
        cout << "Tidak ada penulis didalam list" << endl;
    } else if (P->list_novel.first == NULL) {
        cout << "tidak ada novel yang dibuat oleh penulis" << endl;
    } else {

        adr_novel X = P->list_novel.first;
        int i = 1;
        while (X != NULL) {
            cout << "[" << i++ << "]" << endl;
            cout << "Judul  : " << X->judul << endl;
            cout << "Penulis  : " << X->penulis << endl;
            cout << "Collab : " << X->collab << endl;
            cout << "Rilis  : " << X->tahunRilis << endl;
            X = next(X);
        }
    }
}

void show_all_novel(novel L){
    if (L.first == NULL) {
        cout<<"tidak ada novel dalam list"<<endl;
    } else {
        adr_novel X = first(L);
        int i = 1;
        while (X != NULL) {
            cout << "[" << i++ << "]" << endl;
            cout << "Judul  : " << X->judul << endl;
            cout << "Penulis  : " << X->penulis << endl;
            cout << "Collab : " << X->collab << endl;
            cout << "Rilis  : " << X->tahunRilis << endl;
            X = next(X);
        }
    }
}

void show_semua_penulis_dengan_novelnya(penulis M) {
//show all data, penulis dan novelnya
    adr_penulis P = M.first;
    adr_novel x;
    int i = 1;
    if (P == NULL) {
        cout << "Tidak ada penulis dalam list" << endl;
    } else {
        while (P != NULL) {
            cout<<"["<<i++<<"]"<<endl;
            cout<<"Nama penulis: "<<P->nama<<endl;
            cout<<"TTL: "<<P->tempatTanggalLahir<<endl;

            cout<<"novel yang dibuat:"<<endl;
            x = P->list_novel.first;
            if (x == NULL) {
                cout<<"   [TIDAK ADA]"<<endl;
            }
            while (x != NULL) {
                cout<<"-"<<x->judul;
                if (x->collab != "-") {
                    if (x->collab == P->nama) {
                        cout<<" By "<<x->penulis<<" Dan "<<x->collab<<endl;
                    } else {
                        cout<<" Dan "<<x->collab<<endl;
                    }

                } else {
                    cout<<endl;
                }
                x = x->next;
            }
            P = P->next;
            cout<<endl;
        }
    }
}

void show_judul_by_dua_penulis(novel L){
    if (L.first == NULL) {
        cout<<"tidak ada novel dalam list"<<endl;
    } else {
        adr_novel X = first(L);
        int i = 1;
        while (X != NULL) {
            if(X->collab != "-"){
                cout << "[" << i++ << "]" << endl;
                cout << "Judul  : " << X->judul << endl;
            }
            X = next(X);
        }
    }
}

int menu(){
    cout<<"---- Menu ----"<<endl<<endl;
    cout<<"Silahkan pilih apa yang anda ingin lakukan:"<<endl;
    cout<<"1. Tambah penulis baru"<<endl;
    cout<<"2. Tambah novel baru"<<endl;
    cout<<"3. Hapus data penulis"<<endl;
    cout<<"4. Hapus data novel"<<endl;
    cout<<"5. Tampilkan semua data penulis"<<endl;
    cout<<"6. Tampilkan semua data novel yang ada di sistem"<<endl;
    cout<<"7. Tampilkan semua data novel yang dibuat oleh seorang penulis"<<endl;
    cout<<"8. Tampilkan semua data penulis dengan novelnya"<<endl;
    cout<<"9. Tampilkan semua data novel yang ditulis oleh dua penulis"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<endl<<endl;
    cout<<"Input nomor: ";
    int angka;
    cin>>angka;

    return angka;
}



