#include "header.h"

int main()
{
    //list
    penulis M;
    novel L;

    //create list
    create_listpenulis(M);
    create_listnovel(L);

    //define adr
    adr_penulis P;
    adr_novel X;

    //input penulis
    std::string nama;
    string TTL;

    //input novel
    string judul;
    string penulis1;
    string penulis2;
    string isCollab;
    int tahun_rilis;

    //buat ulang
    string answer;

    int pilihan = menu();

    while (pilihan > 0 && pilihan <= 9){
        switch (pilihan) {
            case 1:
                std::cin.ignore();
                cout<<"Masukkan nama penulis: ";
                std::getline(cin, nama);

                cout<<"Masukkan tempat dan tanggal lahir penulis: ";
                std::getline(cin, TTL);

                P = create_penulis(nama, TTL);
                insert_penulis(M, L, P);

                cout<<"Kembali ke menu utama? (Y/N): ";
                    cin>>answer;
                    cout<<endl;
                    if (answer == "Y") {
                        pilihan = menu();
                        break;
                    } else{
                        break;
                    }

            case 2:
                cout<<"Masukkan judul novel: ";
                std::cin.ignore();
                std::getline(cin, judul);

                cout<<"Masukkan nama penulis: ";
                std::getline(cin, penulis1);

                cout<<"Kolaborasi?(Y/N): ";
                cin>>isCollab;

                if (isCollab == "Y") {
                    cout<<"Masukkan nama penulis lain: ";
                    std::cin.ignore();
                    std::getline(cin, penulis2);
                } else {
                    penulis2 = "-";
                }

                cout<<"Masukkan Tahun Rilis: ";
                cin>>tahun_rilis;

                X = create_novel(judul, penulis1, penulis2, tahun_rilis);
                insert_novel(L, X);

                add_novel_to_penulis(M, L, penulis1, judul);

                if (isCollab == "Y") {
                    add_novel_to_penulis(M, L, penulis2, judul);
                }

                cout<<"Kembali ke menu utama? (Y/N) :";
                    cin>>answer;
                    cout<<endl;
                    if (answer == "Y") {
                        pilihan = menu();
                        break;
                    } else{
                        break;
                    }

            case 3:
                cout<<"Masukkan nama penulis yang ingin di delete: ";
                std::cin.ignore();
                std::getline(cin, nama);

                delete_penulis(M, nama);

                cout<<"Kembali ke menu utama? (Y/N) :";
                    cin>>answer;
                    cout<<endl;
                    if (answer == "Y") {
                        pilihan = menu();
                        break;
                    } else{
                        break;
                    }

            case 4:
                cout<<"Masukkan judul novel yang ingin di delete: ";
                std::cin.ignore();
                std::getline(cin, judul);

                del_novel(M, L, judul);

                cout<<"Kembali ke menu utama? (Y/N) :";
                    cin>>answer;
                    cout<<endl;
                    if (answer == "Y") {
                        pilihan = menu();
                        break;
                    } else{
                        break;
                    }

            case 5:
                show_penulis(M);

                cout<<"Kembali ke menu utama? (Y/N) :";
                    cin>>answer;
                    cout<<endl;
                    if (answer == "Y") {
                        pilihan = menu();
                        break;
                    } else{
                        break;
                    }

            case 6:
                show_all_novel(L);

                cout<<"Kembali ke menu utama? (Y/N) :";
                    cin>>answer;
                    cout<<endl;
                    if (answer == "Y") {
                        pilihan = menu();
                        break;
                    } else{
                        break;
                    }

            case 7:
                cout<<"Masukkan nama penulis: ";
                std::cin.ignore();
                std::getline(cin, nama);

                show_novel(M, nama);

                cout<<"Kembali ke menu utama? (Y/N) :";
                    cin>>answer;
                    cout<<endl;
                    if (answer == "Y") {
                        pilihan = menu();
                        break;
                    } else{
                        break;
                    }

            case 8:
                cout<<"list penulis dan novelnya: "<<endl;
                show_semua_penulis_dengan_novelnya(M);

                cout<<"Kembali ke menu utama? (Y/N) :";
                    cin>>answer;
                    cout<<endl;
                    if (answer == "Y") {
                        pilihan = menu();
                        break;
                    } else{
                        break;
                    }

            case 9:
                cout<<"List Buku yang ditulis oleh dua penulis"<<endl;
                show_judul_by_dua_penulis(L);

                cout<<"Kembali ke menu utama? (Y/N) :";
                cin>>answer;
                cout<<endl;
                    if (answer == "Y") {
                        pilihan = menu();
                        break;
                    } else{
                        break;
                    }
        }
    }

    return 0;
}
