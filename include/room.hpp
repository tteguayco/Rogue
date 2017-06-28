
class Room {
private:
    unsigned topLimit_;
    unsigned bottomLimit_;
    unsigned leftLimit_;
    unsigned rightLimit_;

public:
    Room(unsigned topLimit, unsigned bottomLimit, unsigned leftLimit,
      unsigned rightLimit);
    ~Room();
    unsigned getTopLimit(void);
    unsigned getBottomLimit(void);
    unsigned getLeftLimit(void);
    unsigned getRightLimit(void);
};
