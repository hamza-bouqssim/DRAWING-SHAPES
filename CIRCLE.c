#include <mlx.h>

    typedef struct c_info
    {
    void *mlx;
    void *win;
        
    } t_crcl;

int close_win(void *param)
{
    t_crcl *data;
    data = param;
    mlx_destroy_image(data->mlx, data->win);
    exit(0);
}

int main()
{
    t_crcl data;
    int x,y;
    int a=250, b =250;
    
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 500, 500, "CIRCLE");
    x = 0;
    while(x < 500)
    {
        y = 0;
        while(y < 500)
        {
           
            if(((x - a) * (x - a)) + ((y - b) * (y - b))<= 125 * 125)
            {
                mlx_pixel_put(data.mlx, data.win, x, y, 0x0000ff);
            }
            y++;
        }
        x++;
    }
    mlx_hook(data.win,17, 0, close_win, &data);
    mlx_loop(data.mlx);
}