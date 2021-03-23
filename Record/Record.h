using namespace std;
class abstract
{
protected:
    string record_name;
    string artist_name;
    string year_released;
    int price;

public:
    virtual void show () = 0;

    abstract ();
    abstract (string record, string artist, string year, int p);
    string get_val1 ();
    string get_val2 ();
    string get_val3 ();
    int get_val4 ();
};

class record : public abstract
{
public:
    record ();
    record (string record, string artist, string year, int p);
    virtual void show();
};

class Price
{
    int total_price;

public:
    Price ();
    void set_num (int x);
    int get_price ();
    friend Price operator + (Price op, int k);
};

void BUY ();
void ADD ();
void menu ();
