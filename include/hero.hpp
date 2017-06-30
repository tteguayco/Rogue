
const unsigned DEFAULT_NUMBER_OF_LIVES = 5;

class Hero {
private:
    unsigned currentRow_;     // Row of the map occupied by the hero
    unsigned currentCol_;     // Column of the map occupied by the hero
    unsigned numOfLives_;     // Number of available lives for the hero
    bool     hasAmulet_;      // True if the hero has already got the amulet
    bool     hasWon_;         // True if the hero has arrived to the access
                              // point with the amulet

public:
    Hero(unsigned initialRow, unsigned initialCol);
    ~Hero();
    unsigned getRow();
    unsigned getCol();
    bool hasAmulet(void);
    bool hasWon(void);
    void markAsWinner(void);
    void takeAmulet(void);
    void dropAmulet(void);
    void setRow(unsigned aRow);
    void setCol(unsigned aCol);
    void decreaseLife(void);
    bool isDead(void);
    unsigned getNumberOfLives(void);
    void moveUp(void);
    void moveDown(void);
    void moveToLeft(void);
    void moveToRight(void);
};
