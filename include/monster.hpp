
class Monster {
private:
    unsigned row_;
    unsigned col_;

public:
    Monster(unsigned initialRow, unsigned initialCol);
    ~Monster();
    unsigned getRow();
    unsigned getCol();
    void setRow(unsigned aRow);
    void setCol(unsigned aCol);
};
