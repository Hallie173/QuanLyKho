#include <iostream>
#include "Supplier.h"
#include "Customer.h"
#include "Object.h"
using namespace std;
int main()
{
    Customer c1;
    Supplier s1;
    Object ob1;
    int opt;
    do
    {
        cout << "QUAN LY THONG TIN:" << endl;
        cout << "1. Khach hang" << endl << "2. Nha cung cap" << endl << "3. Mat hang" << endl << "4. Hoa don nhap" << endl << "5. Hoa don xuat" << endl << "0. Thoat" << endl << "Select an option: ";
        cin >> opt;
        switch (opt)
        {
            case 1:
            {
                cout << "\n\t\t\t\t""BANG KHACH HANG\n" << endl;
                c1.Show(); //Show all Customer
                int EditOpt;
                do
                {
                    cout << endl << "1. Them khach hang" << endl << "2. Sua thong tin khach hang" <<
                    endl << "3. Xoa thong tin khach hang" << endl << "4. Tim kiem khach hang" <<
                    endl << "0. Quay lui" << endl << "Select an option: ";
                    cin >> EditOpt;
                    switch (EditOpt)
                    {
                        case 1:
                        {
                            c1.Add(); //Add Customer
                            cout << "\n\t\t\t\t""BANG KHACH HANG\n" << endl;
                            c1.Show(); //Show all customer after update;
                            break;
                        }
                        case 2:
                        {
                            //string Id;
                            //cout << "Nhap Id khach hang can chinh sua thong tin: ";
                            //cin >> Id;
                            //c1.Change(Id); // Change Customer
                            cout << endl << "Change Customer" << endl;
                            break;
                        }
                        case 3:
                        {
                            string Id;
                            cout << "Nhap Id khach hang can xoa thong tin: ";
                            cin >> Id;
                            c1.Delete(Id); // Delete Customer
                            c1.Show();
                            cout << endl << "Delete Customer" << endl;
                            break;
                        }
                        case 4:
                        {
                            //string DisplayName;
                            //cout << "Nhap ten khach hang can tim kiem: ";
                            //cin >> DisplayName;
                            //c1.Find(DisplayName); //Find Customer has name: DisplayName
                            cout << endl << "Find Customer" << endl;
                            break;
                        }
                        case 0:
                        {
                            EditOpt = -1;
                            opt = -1;
                            cout << endl;
                            break;
                        }
                        default:
                        {
                            cout << endl << "Invalid Option!!!" << endl << endl;
                            EditOpt = 0;
                            break;
                        }
                    }
                }
                while (EditOpt >= 0 && EditOpt <= 4);
                break;
            }
            case 2:
            {
                cout << "\n\t\t\t\t""BANG NHA CUNG CAP\n" << endl;
                s1.Show();     //Show all Suplier
                int EditOpt;
                do
                {
                    cout << endl << "1. Them nha cung cap" << endl << "2. Sua thong tin nha cung cap" <<
                    endl << "3. Xoa thong tin nha cung cap" << endl << "4. Tim kiem nha cung cap" <<
                    endl << "0. Quay lui" << endl << "Select an option: ";
                    cin >> EditOpt;
                    switch (EditOpt)
                    {
                        case 1:
                        {
                            s1.Add(); //Add Supplier
                            cout << "\n\t\t\t\t""BANG NHA CUNG CAP\n" << endl;
                            s1.Show(); //Show all Supplier after update
                            break;
                        }
                        case 2:
                        {
                            //string Id;
                            //cout << "Nhap id nha cung cap can chinh sua thong tin: ";
                            //cin >> Id;
                            //s1.Change(Id); // Change Supplier
                            cout << endl << "Change Supplier" << endl;
                            break;
                        }
                        case 3:
                        {
                            string Id;
                            cout << "Nhap Id nha cung cap can xoa thong tin: ";
                            cin >> Id;
                            s1.Delete(Id); // Delete Supplier
                            s1.Show();
                            //cout << endl << "Delete Supplier" << endl;
                            break;
                        }
                        case 4:
                        {
                            //string DisplayName;
                            //cout << "Nhap ten nha cung cap can tim kiem: ";
                            //cin >> DisplayName;
                            //s1.Find(DisplayName); //Find Supplier has name: DisplayName
                            cout << endl << "Find Supplier" << endl;
                            break;
                        }
                        case 0:
                        {
                            EditOpt = -1;
                            opt = -1;
                            cout << endl;
                            break;
                        }
                        default:
                        {
                        cout << endl << "Invalid Option!!!" << endl << endl;
                        EditOpt = 0;
                        break;
                    }
                    }
                } while (EditOpt >= 0 && EditOpt <= 4);
                break;
            }
            case 3:
            {
                cout << "\n\t\t\t\t""BANG MAT HANG\n" << endl;
                ob1.Show();     //Show All Object
                int EditOpt;
                do
                {
                    cout << endl << "1. Them mat hang" << endl << "2. Sua mat hang" <<
                    endl << "3. Xoa mat hang" << endl << "4. Tim kiem mat hang" <<
                    endl << "0. Quay lui" << endl << "Select an option: ";
                    cin >> EditOpt;
                    switch (EditOpt)
                    {
                        case 1:
                        {
                            ob1.Add(); //Add Object
                            cout << "\n\t\t\t\t""BANG MAT HANG\n" << endl;
                            ob1.Show(); // Show all Object after update
                            break;
                        }
                        case 2:
                        {
                            //string Id;
                            //cout << "Nhap id mat hang can chinh sua thong tin: ";
                            //cin >> Id;
                            //ob1.Change(Id); // Change Object
                            cout << endl << "Change Object" << endl;
                            break;
                        }
                        case 3:
                        {
                            string Id;
                            cout << "Nhap Id mat hang can xoa thong tin: ";
                            cin >> Id;
                            ob1.Delete(Id); // Delete Object
                            ob1.Show();
                            //cout << endl << "Delete Object" << endl;
                            break;
                        }
                        case 4:
                        {
                            //string DisplayName;
                            //cout << "Nhap ten mat hang can tim kiem: ";
                            //cin >> DisplayName;
                            //ob1.Find(DisplayName); //Find Object has name: DisplayName
                            cout << endl << "Find Object" << endl;
                            break;
                        }
                        case 0:
                        {
                            EditOpt = -1;
                            opt = -1;
                            cout << endl;
                            break;
                        }
                        default:
                        {
                        cout << endl << "Invalid Option!!!" << endl << endl;
                        EditOpt = 0;
                        break;
                    }
                    }
                } while (EditOpt >= 0 && EditOpt <= 4);
                break;
            }
            case 4:
            {

            }
            case 5:
            {

            }
            case 0:
            {
                return 0;
            }
            default:
            {
                cout << endl << "Invalid Option!!!" << endl << endl;
                opt = -1;
                break;
            }
        }
    } while (opt < 0 || opt > 5);
    return 0;
}
