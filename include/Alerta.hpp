#ifndef ALERTA_H
#define ALERTA_H

#include <iostream>
#include <chrono>
#include <string>
#include <ctime>
#include <iomanip>

class Alerta {
private:
    std::chrono::system_clock::time_point alerta_time;
    bool alerta_disparado;

public:
    Alerta();

    std::string get_alerta_time() const;

    void verificar_e_disparar();

    bool is_disparado() const;
};

#endif // ALERTA_H
