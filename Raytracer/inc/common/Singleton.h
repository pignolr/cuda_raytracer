#pragma once

namespace raytracer::common {
    template <class T>
    class Singleton {
    protected:
        Singleton() {};
    public:
        // Disable copy
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(Singleton&&) = delete;

        static Singleton<T>& get_instance()
        {
            static T instance;
            return instance;
        }
    };
}
