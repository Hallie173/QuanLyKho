#include <iostream>
using namespace std;
class Supplier{
    protected:
        string Id;
        string DisplayName;
        string Address;
        string Phone;
    public:
        Supplier(string = "", string = " ", string = " ", string = "0000000000");
        ~Supplier();
        void setId(string = "");
        string getId() const;
        void setDisplayName(string = "");
        string getDisplayName() const;
        void setAddress(string = "");
        string getAddress() const;
        void setPhone(string = "");
        string getPhone() const;
        friend istream& operator>>(istream&, Supplier&);
        friend ostream& operator<<(ostream&, const Supplier&);
        void Show();
        void Add();
        void Delete(string = "");
        //void Change(string = "");
};
