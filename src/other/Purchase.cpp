class Purchase {
    int ticketID;
    int price;
    string product_name;
    string note;

public:
    static const string class_name;

    Purchase(int _id, int _price, string _name, string _note):
        ticketID(_id),
        price(_price),
        product_name(_name),
        note(_note) {}

    void print() {
        cout << "Purchase data of " << product_name << endl;
        cout << "\tTicket ID: " << ticketID << endl;
        cout << "\t- Price " << price << endl;
        cout << "\t- Notes:" << endl;
        cout << note << endl;
    }
};
const string Purchase :: class_name = "PurchaseClass";