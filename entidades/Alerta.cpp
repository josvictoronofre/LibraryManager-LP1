#include "../include/Alerta.hpp"

// Construtor
Alerta::Alerta() {
    auto now = std::chrono::system_clock::now();
    alerta_time = now + std::chrono::hours(24 * 30); // Alerta depois de 30 dias
    alerta_disparado = false;
}

// Retorna o horário do alerta formatado
std::string Alerta::get_alerta_time() const {
    std::time_t time = std::chrono::system_clock::to_time_t(alerta_time);
    std::tm* local_time = std::localtime(&time);

    // Formata a data
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
    return std::string(buffer);
}

// Verifica se o alerta deve ser disparado
void Alerta::verificar_e_disparar() {
    if (!alerta_disparado) {
        auto now = std::chrono::system_clock::now();
        if (now >= alerta_time) {
            alerta_disparado = true;
            std::cout << "Alerta: O prazo de devolução venceu! Data: " << get_alerta_time() << std::endl;
        }
    }
}

// Retorna se o alerta já foi disparado
bool Alerta::is_disparado() const {
    return alerta_disparado;
}
