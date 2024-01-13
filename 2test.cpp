#include <iostream>
#include <string>
#include <limits>
using namespace std;
class User
{
protected:
    string name;
    string gender;
    int age;

public:
    User(){};
    User(string n, string g, int a);
    virtual void Set_name(string n) = 0;
    virtual void Set_gender(string n) = 0;
    virtual void Set_age(int n) = 0;
    virtual string Get_name() = 0;
    virtual string Get_gender() = 0;
    virtual int Get_age() = 0;
};
class management : private User
{
private:
    string adminuser = "ali";
    string adminpass = "ali";
    int cnic;
    string username;
    string password;

public:
    management(){};
    management(string n, string g, int a, int i, string un, string pd);
    void Set_name(string n);
    void Set_gender(string n);
    void Set_age(int n);
    void Set_cnic(int n);
    void Set_username(string n);
    void Set_password(string n);
    string Get_name();
    string Get_gender();
    int Get_age();
    int Get_cnic();
    string Get_username();
    string Get_password();
    string Get_adusername();
    string Get_adpass();
    void Creataccount();
    void loginaccount(string user, string pass);
    void display_available_management();
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

public:
    boat(){};
    boat(string n, int m, string r);
    // virtual void display_all_yatchs() = 0;
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
    cargo_ship(string mak, int mod, string vart, int ccapacity, string ctype, int sz, int cntcapac, string freg, int spd, int rng, string dsp);
    void set_cargo_capacity(int n);
    void set_cargo_type(string n);
    void set_size(int n);
    void set_container_capacity(int n);
    void set_flag_and_registration(string n);
    void set_speed(int n);
    void set_range(int n);
    void set_details(string n);
    int get_cargo_capacity();
    string get_cargo_type();
    int get_size();
    int get_container_capacity();
    string get_flag_and_registration();
    int get_speed();
    int get_range();
    string get_details();
};
class yatch : protected boat
{
private:
    float per_day_rent;
    int size;        // In feets and inches
    string design;   // Modern, classic, expedition, or custom design styles.
    string Material; // Common materials include fiberglass, aluminum, steel, or a combination
    int speed;       // in KMPH
    int Crew_Capacity;
    string Flag_and_Registration; // The country under whose flag the yacht is registered.

public:
    yatch(){};
    yatch(string mak, int mod, string vart, float rnt, int s, string dsg, string mtr, int spd, int ccapacity, string reg);
    void set_make(string n);
    void set_pdr(float n);
    void set_model(int n);
    void set_varient(string n);
    void set_size(int n);
    void set_design(string n);
    void set_material(string n);
    void set_speed(int n);
    void set_crew_capacity(int n);
    void set_Flag_and_Registration(string n);
    string get_make();
    int get_model();
    string get_varient();
};

int i = 0;
int count = 0;
int yc = 0;
int main()
{
    int opt;
    char choice;

    management m[10];
    string user, pass;

    yatch y[100];
    int size, speed, Crew_Capacity, model;
    string design, Material, Flag_and_Registration, discription, make, varient;
    float per_day_rent;

    do
    {
        system("cls");
        cout << "\t       ---------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t       |                                                                                                                                     |" << endl;
        cout << "\t       |                      ******************Welcome to Ships reservation and management system******************                         |" << endl;
        cout << "\t       |                                                                                                                                     |" << endl;
        cout << "\t       ---------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "\t\t                    ----------------------------------------------" << endl;
        cout << "\t\t                   |                                              |" << endl;
        cout << "\t\t                   |   1). Management login                       |" << endl;
        cout << "\t\t                   |   2). Private Reservations                   |" << endl;
        cout << "\t\t                   |   3). Internamional Travels                  |" << endl;
        cout << "\t\t                   |   4). cargo shipments                        |" << endl;
        cout << "\t\t                   |                                              |" << endl;
        cout << "\t\t                    ----------------------------------------------" << endl;
        cout << "\n\t\t                   Enter your option or press 5 to qxit...";
        while (!(cin >> opt))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        switch (opt)
        {
        case 1:
            do
            {
                system("cls");

                cout << "\n\t\t\t------------------------------------------" << endl;
                cout << "\t\t\t*****Welcome to management login page*****" << endl;
                cout << "\t\t\t------------------------------------------" << endl;
                cout << "1).Login to existing account" << endl;
                cout << "2).Create an account" << endl;
                cout << "3).Details of available Officers" << endl;
                cout << "Enter your option or press 4 to exit...";
                while (!(cin >> opt))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter an integer: ";
                }
                switch (opt)
                {
                case 1:
                    system("cls");
                    cout << "\n\t\t\t---------------------" << endl;
                    cout << "\t\t\tWelcome to login page" << endl;
                    cout << "\t\t\t---------------------" << endl;

                    cout << "\t\tEnter your username: ";
                    cin >> user;
                    cout << "\n\t\tEnter your password: ";
                    cin >> pass;
                    for (int i = 0; i < count; i++)
                    {
                        if (user == m[i].Get_username() && pass == m[i].Get_password())
                        {
                            m[i].loginaccount(user, pass);
                            break;
                        }
                        else
                        {
                            do
                            {
                                cout << "\n\t\t-----------------------------" << endl;
                                cout << "\t\tInvalid username or password!" << endl;
                                cout << "\t\t-----------------------------" << endl;
                                cout << "\n\t\tPress 'q' to exit...";
                                cin >> choice;
                            } while (choice != 'q');
                        }
                    }
                    break;
                case 2:
                    m[i].Creataccount();
                    i++;
                    count++;
                    break;
                case 3:
                    system("cls");
                    cout << "\n\t\t\t---------------------------------------" << endl;
                    cout << "\t\t\t******management officers details******" << endl;
                    cout << "\t\t\t---------------------------------------" << endl;
                    do
                    {
                        for (int i = 0; i < count; i++)
                        {
                            m[i].display_available_management();
                        }
                        cout << "\t\tPress 'q' to exit...";
                        cin >> choice;
                    } while (choice != 'q');

                    break;
                }
            } while (opt != 4);

            break;
        case 2:
            do
            {
                system("cls");
                cout << "\t\t\t--------------------------" << endl;
                cout << "\t\t\t***Private reservations***" << endl;
                cout << "\t\t\t--------------------------" << endl;
                cout << "\n1). Add a new yatch" << endl;
                cout << "2).Make reservation" << endl;
                cout << "3).Available yatch" << endl;
                cout << "Enter your option or press 4 to exit...";
                while (!(cin >> opt))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter an integer: ";
                }
                switch (opt)
                {
                case 1:
                    system("cls");
                    cout << "\n\t\t\t\t--------------------------------" << endl;
                    cout << "\t\t\t\t***Welcome to management page***" << endl;
                    cout << "\t\t\t\t--------------------------------" << endl;
                    cout << "\n\t\tEnter your username: ";
                    cin >> user;
                    cout << "\n\t\tEnter your password: ";
                    cin >> pass;
                    for (int i = 0; i < count; i++)
                    {
                        if (user == m[i].Get_username() && pass == m[i].Get_password())
                        {
                            cout << "\n\n\t\t\t\t\t\t-------------------" << endl;
                            cout << "\t\t\t\t\t\t***Add new Yatch***" << endl;
                            cout << "\t\t\t\t\t\t-------------------" << endl;
                            cout << "\n\n\t\tEnter make of yatch: ";
                            cin >> make;
                            y[yc].set_make(make);
                            cout << "\t\tEnter model of yatch: ";
                            cin >> model;
                            y[yc].set_model(model);
                            cout << "\t\tEnter varient of yatch: ";
                            cin >> varient;
                            y[yc].set_varient(varient);
                            cout << "\t\tEnter per_day_rent of yatch: ";
                            cin >> per_day_rent;
                            y[yc].set_pdr(per_day_rent);
                            cout << "\t\tEnter size of yatch: ";
                            cin >> size;
                            y[yc].set_size(size);
                            cout << "\t\tEnter design of yatch: ";
                            cin >> design;
                            y[yc].set_design(design);
                            cout << "\t\tEnter Material of yatch: ";
                            cin >> Material;
                            y[yc].set_material(Material);
                            cout << "\t\tEnter speed of yatch: ";
                            cin >> speed;
                            y[yc].set_speed(speed);
                            cout << "\t\tEnter Crew_Capacity of yatch: ";
                            cin >> Crew_Capacity;
                            y[yc].set_crew_capacity(Crew_Capacity);
                            cout << "\t\tEnter Flag_and_Registration of yatch: ";
                            cin >> Flag_and_Registration;
                            y[yc].set_Flag_and_Registration(Flag_and_Registration);
                            yc++;
                        }
                        else
                        {
                            do
                            {
                                cout << "\n\t\t-----------------------------" << endl;
                                cout << "\t\tInvalid username or password!" << endl;
                                cout << "\t\t-----------------------------" << endl;
                                cout << "\n\t\tPress 'q' to exit...";
                                cin >> choice;
                            } while (choice != 'q');
                        }
                    }
                    break;
                }
            } while (opt != 4);
            break;
        }
    } while (opt != 5);
}

User::User(string n, string g, int a)
{
    name = n;
    gender = g;
    age = a;
}
// Management class functions
management::management(string n, string g, int a, int i, string un, string pd) : User(n, g, a)
{
    name = n;
    gender = g;
    age = a;
    cnic = i;
    username = un;
    password = pd;
}
string management::Get_adusername()
{
    return adminuser;
}
void management::Set_name(string n)
{
    name = n;
}
void management::Set_gender(string n)
{
    gender = n;
}
void management::Set_age(int n)
{
    age = n;
}
void management::Set_cnic(int n)
{
    cnic = n;
}
void management::Set_username(string n)
{
    username = n;
}
void management::Set_password(string n)
{
    password = n;
}
string management::Get_name()
{
    return name;
}
string management::Get_gender()
{
    return gender;
}
int management::Get_age()
{
    return age;
}
int management::Get_cnic()
{
    return cnic;
}
string management::Get_username()
{
    return username;
}
string management::Get_password()
{
    return password;
}
void management::Creataccount()
{
    int ag, i;
    string nam, gen, user, pass;
    string adpass, aduser;
    char opt;

    system("cls");
    cout << "\t\t\t\t------------------------" << endl;
    cout << "\t\t\t\t***Create New account***" << endl;
    cout << "\t\t\t\t------------------------" << endl;
    cout << "\n\n\t\t\tEnter admin username: ";
    cin >> aduser;
    cout << "\t\t\tEnter admin password: ";
    cin >> adpass;
    if (adpass == adminpass && aduser == adminuser)
    {

        cout << "\n\t\t\t\t------------------------------------------------" << endl;
        cout << "\t\t\t\t***Welcome to new management account creation***" << endl;
        cout << "\t\t\t\t------------------------------------------------" << endl;

        cout << "\n\t\tEnter your name: ";
        cin >> nam;
        Set_name(nam);
        cout << "\t\tEnter your gender(male/female): ";
        cin >> gen;
        Set_gender(gen);
        cout << "\t\tEnter your age: ";
        while (!(cin >> ag))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        Set_age(ag);
        cout << "\t\tEnter your cnic: ";
        while (!(cin >> i))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        Set_cnic(i);
        cout << "\t\tCreate a username: ";
        cin >> user;
        Set_username(user);
        cout << "\t\tCreate password: ";
        cin >> pass;
        Set_password(pass);
        do
        {
            cout << "\n\t\t\t\t------------------------------------" << endl;
            cout << "\t\t\t\tYour account is created sucessfuilly" << endl;
            cout << "\t\t\t\t------------------------------------" << endl;
            cout << "\t\tPress 'q' to exit...";
            cin >> opt;
        } while (opt != 'q');
    }
    else
    {
        do
        {
            cout << "\n\t\tUsrename or password is wrong please enter correct password\npress 'q' to exit..." << endl;
            cin >> opt;
        } while (opt != 'q');
    }
}
void management::loginaccount(string user, string pass)
{
    char choice;
    int ag, i, opt;
    string nam, gen;

    do
    {
        system("cls");
        cout << "\n\t\t\t-----------------------" << endl;
        cout << "\t\t\tWelcome to your account" << endl;
        cout << "\t\t\t-----------------------" << endl;

        cout << "\n\t\t1).View details" << endl;
        cout << "\t\t2).Change username" << endl;
        cout << "\t\t3).Change password" << endl;
        cout << "Enter your option or press 4 to exit...";
        while (!(cin >> opt))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        switch (opt)
        {
        case 1:
            do
            {
                cout << "\n\t\t\t------------------" << endl;
                cout << "\t\t\tManagement details" << endl;
                cout << "\t\t\t------------------" << endl;
                cout << "\tName: " << name << endl;
                cout << "\tAge: " << age << endl;
                cout << "\tGender: " << gender << endl;
                cout << "\tCNIC: " << cnic << endl;
                cout << "\tUsername: " << username << endl;
                cout << "\tPassword: " << password << endl;
                cout << "\nPress 'q' to exit...";
                cin >> choice;
            } while (choice != 'q');
            break;
        case 2:
            cout << "\n\t\tEnter your current username: ";
            cin >> user;
            if (user == username)
            {
                cout << "\tEnter your new username: ";
                cin >> user;
                Set_username(user);
                do
                {
                    cout << "\n\t\t\t-------------------------------------" << endl;
                    cout << "\t\t\tusername has been updated sucessfully" << endl;
                    cout << "\t\t\t-------------------------------------" << endl;
                    cout << "\t\tPress 'q' to exit..." << endl;
                    cin >> choice;
                } while (choice != 'q');
            }
            else
            {
                do
                {
                    cout << "Invalid username!\nPress 'q' to exit...";
                    cin >> choice;

                } while (choice != 'q');
            }

            break;
        case 3:
            cout << "\n\t\tEnter your current password: ";
            cin >> pass;
            if (pass == password)
            {
                cout << "\tEnter your new password: ";
                cin >> pass;
                Set_password(pass);
                do
                {
                    cout << "\n\t\t\t-------------------------------------" << endl;
                    cout << "\t\t\tpassword has been updated sucessfully" << endl;
                    cout << "\t\t\t-------------------------------------" << endl;
                    cout << "\t\tPress 'q' to exit..." << endl;
                    cin >> choice;
                } while (choice != 'q');
            }
            else
            {
                do
                {
                    cout << "Invalid password!\nPress 'q' to exit...";
                    cin >> choice;

                } while (choice != 'q');
            }
            break;
        }
    } while (opt != 4);
}
void management::display_available_management()
{
    cout << "\n\t\t\t--------------------" << endl;
    cout << "\t\t\tName: " << name << endl;
    cout << "\t\t\tUsername: " << username << endl;
    cout << "\t\t\tGender: " << gender << endl;
    cout << "\t\t\tAge: " << age << endl;
    cout << "\t\t\tCNIC: " << cnic << endl;
    cout << "\t\t\t--------------------" << endl;
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
boat::boat(string n, int m, string r)
{
    make = n;
    model = m;
    varient = r;
}
yatch::yatch(string mak, int mod, string vart, float rnt, int s, string dsg, string mtr, int spd, int ccapacity, string reg) : boat(mak, mod, vart)
{
    per_day_rent = rnt;
    size = s;
    design = dsg;
    Material = mtr;
    speed = spd;
    Crew_Capacity = ccapacity;
    Flag_and_Registration = reg;
}
void yatch::set_make(string n)
{
    make = n;
}
void yatch::set_model(int n)
{
    model = n;
}
void yatch::set_varient(string n)
{
    varient = n;
}
string yatch::get_make()
{
    return make;
}
int yatch::get_model()
{
    return model;
}
string yatch::get_varient()
{
    return varient;
}
void yatch::set_size(int n)
{
    size = n;
}
void yatch::set_design(string n)
{
    design = n;
}
void yatch::set_material(string n)
{
    Material = n;
}
void yatch::set_speed(int n)
{
    speed = n;
}
void yatch::set_crew_capacity(int n)
{
    Crew_Capacity = n;
}
void yatch::set_pdr(float n)
{
    per_day_rent = n;
}
void yatch::set_Flag_and_Registration(string n)
{
    Flag_and_Registration = n;
}

cargo_ship::cargo_ship(string mak, int mod, string vart,int ccapacity, string ctype, int sz, int cntcapac, string freg, int spd, int rng, string dsp) : boat(mak, mod, vart)
{
    make = mak;
    model = mod;
    varient = vart;
    cargo_capacity = ccapacity;
    cargo_type = ctype;
    size = sz;
    container_capacity = cntcapac;
    flag_and_registration = freg;
    speed = spd;
    range = rng;
    details = dsp;
}
