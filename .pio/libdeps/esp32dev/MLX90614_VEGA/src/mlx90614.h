#ifndef MLX90614_H_
#define MLX90614_H_

#define MLX90614_WRITE_ADDR     0xB4
#define MLX90614_READ_ADDR      0xB5
#define MLX90614_AMBIENT_TEMP   0x06
#define MLX90614_TARGET_TEMP    0x07


#define sclPin 22
#define sdaPin 21

double mlx90614ReadAmbientTempC();
double mlx90614ReadTargetTempC();
void mlx90614Start();
void mlx90614Stop();
void mlx90614Restart();

int udelay(unsigned int count);

#endif
