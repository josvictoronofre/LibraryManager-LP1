#include <iostream>
#include <chrono>
#include <string>
#include <ctime>
#include <iomanip>

class Alerta {
private:
    std::chrono::system_clock::time_point alerta_time;
    bool alerta_disparado = false;
public:
    Alerta() {
        auto now = std::chrono::system_clock::now();
        alerta_time = now + std::chrono::hours(24 * 30); //Alerta depois de 30 dias
    }

    std::string get_alerta_time() const {
        std::time_t time = std::chrono::system_clock::to_time_t(alerta_time);
        std::tm* local_time = std::localtime(&time);

        // Formata a data
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
        return std::string(buffer);
    }

    void verificar_e_disparar() {
        if (!alerta_disparado) {
            auto now = std::chrono::system_clock::now();
            if (now >= alerta_time) {
                alerta_disparado = true;
                std::cout << "Alerta: O prazo de devolução venceu! Data: " << get_alerta_time() << std::endl;
            }
        }
    }

    bool is_disparado() const {
        return alerta_disparado;
    }
};
