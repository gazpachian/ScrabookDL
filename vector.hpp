#ifndef _VECTOR_H
#define _VECTOR_H
class Vector2 {
    private:
        int x;
        int y;
    public:
        Vector2(int x, int y);
        Vector2();
        ~Vector2();
        int getX() const;
        int getY() const;
        void add(Vector2 v);
        void multiply(double m);
};

class Vector3 {
    private:
        int x;
        int y;
        int z;
    public:
        Vector3(int x, int y, int z);
        static Vector3 zero();
        ~Vector3();
        int getX() const;
        int getY() const;
        int getZ() const;
        int getR() const;
        int getG() const;
        int getB() const;
};

#endif
