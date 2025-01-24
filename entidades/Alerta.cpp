#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <ctime>

class Alerta {
    private:
        std::chrono::system_clock::time_point alerta_time;
        bool alerta_disparado = false;

        void monitorar_alarme() {
            while (!alerta_disparado) {
                auto now = std::chrono::system_clock::now();
                if (now >= alerta_time) {
                    alerta_disparado = true;
                    std::cout << "Alerta: O prazo de devolução venceu! Data: " << get_alerta_time() << std::endl;
                    break;
                }
                std::this_thread::sleep_for(std::chrono::hours(24)); // Aguarda 24 horas antes de verificar novamente
            }
        }

    public:
        Alerta() {
            auto now = std::chrono::system_clock::now();
            alerta_time = now + std::chrono::hours(24 * 30); // Adiciona 30 dias
        }

        std::string get_alerta_time() const {
            std::time_t time = std::chrono::system_clock::to_time_t(alerta_time);
            std::tm* local_time = std::localtime(&time);

            // Formatador das datas
            char buffer[100];
            std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
            return std::string(buffer);
        }

        void iniciar() {
            std::thread thread_alarme(&Alerta::monitorar_alarme, this);
            thread_alarme.detach();
        }
};
