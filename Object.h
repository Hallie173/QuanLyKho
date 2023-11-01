#include <iostream>
using namespace std;
class Object{
    protected:
        string Id;
        string DisplayName;
        string IdSupplier;
    public:
        Object(string = "", string = "", string = "");
        ~Object();
        void setId(string = "");
        string getId() const;
        void setDisplayName(string = "");
        string getDisplayName()const;
        void setIdSupplier(string = "");
        string getIdSupplier() const;
        //friend istream& operator>>(istream&, Object&);
        friend ostream& operator<<(ostream&, const Object&);
        void Show();
        void Add();
        void Delete(string = "");
        //void Change();
};
