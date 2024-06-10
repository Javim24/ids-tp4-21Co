/** @file gpio.c
 ** @brief Definición de funciones del módulo gpio
 **/

/* === Headers files inclusions =============================================================== */
#include "gpio.h"

/* === Macros definitions ====================================================================== */

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

#define USE_DYNAMIC_MEM

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/**
 * @brief Estructura privada para controlar un objeto gpio.
 */
struct gpio_s {
    uint8_t port;
    uint8_t bit;
    bool output;
    bool used;
};

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/**
 * @brief Función privada que crea una nueva  instancia  de un objeto gpio usando memoria estática.
 * @return Puntero  a estructura gpio_s.  Devuelve  NULL si no tuvo éxito.
 */
static gpio_t allocate_instance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index];
            result->used = true;
            break;
        }
    }
    return result;
}

/* === Public function implementation ========================================================== */

gpio_t gpio_create(uint8_t puerto, uint8_t pin) {
#ifdef USE_DYNAMIC_MEM
    gpio_t self = malloc(sizeof(struct gpio_s));
#else
    gpiot_t self = allocate_instance();
#endif

    if (NULL != self) {
        self->port = puerto;
        self->bit = pin;
        self->output = false;
    }
    return self;
}

void gpio_set_output(gpio_t self, bool output) {
    self->output = output;
    HAL_GPIO_SET_OUTPUT(self->port, self->bit);
}

void gpio_set_state(gpio_t self, bool state) {
    if (self->output) {
        HAL_GPIO_SET_STATE(self->port, self->bit);
    }
}

bool gpio_get_state(gpio_t self) {
    return HAL_GPIO_GET_STATE(self->port, self->bit);
}

/* === End of documentation ==================================================================== */
