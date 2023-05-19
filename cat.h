#pragma once

namespace animals
{
    class Cat
    {
    public:
        Cat(){};
        void meow();
    };
    class MiniCat : public Cat
    {
    public:
        MiniCat(){};
    };
}