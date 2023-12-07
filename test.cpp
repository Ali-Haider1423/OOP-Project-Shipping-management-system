#include <iostream>
using namespace std;
class User
{
protected:
    string name;
    string gender;
    int age;

public:
    User(string n, string g, int a);
    void Set_name(string n);
    void Set_gender(string n);
    void Set_age(int n);
    string Get_name();
    string Get_gender();
    int Get_age();
};

class management : private User
{
private:
    int id;
    string username;
    string password;

public:
    management(string n, string g, int a, int i, string un, string pd);
    void Set_id(int n);
    void Set_username(string n);
    void Set_password(string n);
    int Get_id();
    string Get_username();
    string Get_password();
};

class customer : private User
{
private:
    string Permanant_adress;
    string Current_location;
    int phone_number;
    float advance_payment;

public:
    customer(string n, string g, int a, string Padress, string Clocation, int pnum, float adpaymt);
    void Set_permanent_adress(string n);
    void Set_current_location(string n);
    void Set_phone_number(int n);
    void Set_advance_payment(float n);
    string get_permanent_adress();
    string get_current_location();
    int get_phone_number();
    float get_advance_payment();
};

class boat
{
protected:
    string make;
    int model;
    string varient;
    float per_day_rent;

public:
    boat(string n, int m, string r, float pdr);
    void set_make(string n);
    void set_model(int n);
    void set_varient(string n);
    string get_make();
    int get_model();
    string get_varient();
};
class cargo_ship : private boat
{
private:
    int cargo_capacity;           // The amount of cargo, measured in terms of tonnage or TEUs (twenty-foot equivalent units), that a ship can carry.
    string cargo_type;            // Different ships are designed for specific types of cargo, such as container ships, bulk carriers, general cargo ships, or specialized vessels for liquids (tankers) or dry bulk (bulk carriers).
    int size;                     // Length overall (LOA), breadth, and draft determine the physical size of the ship.
    int container_capacity;       // For container ships, the number of containers it can carry and the capacity for different container sizes (20-foot, 40-foot, etc.).
    string flag_and_registration; // under which country it is registereg
    int speed;
    int range; // the distance it can cover on a single voyage before refueling.
    string details;

public:
    cargo_ship(string mak, int mod, string vart, float rnt, int ccapacity, string ctype, int sz, int cntcapac, string freg, int spd, int rng, string dsp);
};

class yatch : private boat
{
private:
    int size;        // In feets and inches
    string design;   // Modern, classic, expedition, or custom design styles.
    string Material; // Common materials include fiberglass, aluminum, steel, or a combination
    int speed;       // in KMPH
    int Crew_Capacity;
    string Flag_and_Registration; // The country under whose flag the yacht is registered.
    string discription;

public:
    yatch(string mak, int mod, string vart, float rnt, int s, string dsg, string mtr, int spd, int ccapacity, string reg, string dicp);
    void set_size(int n);
    void set_design(string n);
    void set_material(string n);
    void set_speed(int n);
    void set_crew_capacity(int n);
};
void Management_page()
{
    int opt;
    do
    {
        system("cls");
        cout << "\n\t\t\t------------------------------------------" << endl;
        cout << "\t\t\t*****Welcome to management login page*****" << endl;
        cout << "\t\t\t------------------------------------------" << endl;
        cout << "1.Login to existing account" << endl;
        cout << "2.Create an account" << endl;
        cout << "3.Enter your option or press 3 to exit...";
        cin >> opt;
    } while (opt != 3);
}
void Private_reservations()
{
    int opt;
    do
    {
        system("cls");
        cout << "\t\t\t--------------------------" << endl;
        cout << "\t\t\t***Private reservations***" << endl;
        cout << "\t\t\t--------------------------" << endl;
        cout << "\n1).Make reservation" << endl;
        cout << "2).Available yatch" << endl;
        cout << "3).Available Dates" << endl;
        cout << "Enter your option or press 4 to exit..." << endl;
        cin >> opt;
    } while (opt != 4);
}
int main()
{
    int opt;
    do
    {
        system("cls");
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t******************Welcome to Ships reservation and management system******************" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

        cout << "\n\t\t1.Management login" << endl;
        cout << "\t\t2.Private Reservations" << endl;
        cout << "\t\t3.Internamional Travels" << endl;
        cout << "\tEnter your option or press 4 to qxit...";
        cin >> opt;
        switch (opt)
        {
        case 1:
            Management_page();
            break;
        case 2:
            Private_reservations();
        }

    } while (opt != 4);
}

User::User(string n, string g, int a)
{
    name = n;
    gender = g;
    age = a;
}
management::management(string n, string g, int a, int i, string un, string pd) : User(n, g, a)
{
    name = n;
    gender = g;
    age = a;
    id = i;
    username = un;
    password = pd;
}
customer::customer(string n, string g, int a, string Padress, string Clocation, int pnum, float adpaymt) : User(n, g, a)
{
    name = n;
    gender = g;
    age = a;
    Permanant_adress = Padress;
    Current_location = Clocation;
    phone_number = pnum;
    advance_payment = adpaymt;
}
boat::boat(string n, int m, string r, float pdr)
{
    make = n;
    model = m;
    varient = r;
    per_day_rent = pdr;
}
yatch::yatch(string mak, int mod, string vart, float rnt, int s, string dsg, string mtr, int spd, int ccapacity, string reg, string dicp) : boat(mak, mod, vart, rnt)
{
    make = mak;
    model = mod;
    varient = vart;
    per_day_rent = rnt;
    size = s;
    design = dsg;
    Material = mtr;
    speed = spd;
    Crew_Capacity = ccapacity;
    Flag_and_Registration = reg;
    discription = dicp;
}
cargo_ship::cargo_ship(string mak, int mod, string vart, float rnt, int ccapacity, string ctype, int sz, int cntcapac, string freg, int spd, int rng, string dsp) : boat(mak, mod, vart, rnt)
{
    make = mak;
    model = mod;
    varient = vart;
    per_day_rent = rnt;
    cargo_capacity = ccapacity;
    cargo_type = ctype;
    size = sz;
    container_capacity = cntcapac;
    flag_and_registration = freg;
    speed = spd;
    range = rng;
    details = dsp;
}
