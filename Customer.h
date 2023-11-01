#include <iostream>
using namespace std;
class Customer{
    protected:
        string Id;
        string DisplayName;
        string Address;
        string Phone;
    public:
        Customer(string = "", string = " ", string = " ", string = "0000000000");
        ~Customer();
        void setId(string = "") ;
        string getId() const;
        void setDisplayName(string = "");
        string getDisplayName() const;
        void setAddress(string = "");
        string getAddress() const;
        void setPhone(string = "");
        string getPhone() const;
        friend istream& operator>>(istream&, Customer&);
        friend ostream& operator<<(ostream&, const Customer&); //in 1 dong
        void Show(); //in toan bo
        void Add();  //nhap du lieu moi vao file text
        void Delete(string = "");
        //void Change();
};
