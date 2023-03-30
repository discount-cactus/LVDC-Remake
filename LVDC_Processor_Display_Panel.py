#LVDC Desktop Programmer
#When connected to the input interface, the connected laptop can send instructions to the board

# 1. Opens instruction file
# 2. Compiles instruction file
# 3. Establishes communication to Arduino programmer
# 4. Opens app window

# https://www.freecodecamp.org/news/python-get-current-time/
# https://towardsdatascience.com/how-to-easily-convert-a-python-script-to-an-executable-file-exe-4966e253c7e9

from datetime import datetime
import tkinter as tk
import tkinter.font as font
import os
import serial
import time

#Establishes the port to link to the ground computer
#address = "/dev/cu.usbserial-14310"
#port = serial.Serial(address,9600)
#port.timeout = 1

H = 1500
W = 600
font1 = 15

i = 0

#Initializes pages
def create_light(xx,yy,w,h,title,ft,bk):
    lightFont = font.Font(family='Helvetica', size=ft)
    l = tk.Label(frame, text=title, bg=bk, font=lightFont)
    l.place(x=xx-(W*0.03),y=yy,width=w,height=h)

def place_lights():
    for widget in frame.winfo_children():
        widget.destroy()
    for widget in frame.winfo_children():
        widget.destroy()

    create_light(15,10,W,40,"Processor Display Panel",30,'#696969');
    create_light(W*0.44,50,100,40,"DATA",font1,'#696969');
    create_light(W*0.76,170,100,40,"OP CODE",font1,'#696969');
    create_light(W*0.29,270,200,40,"MEMORY ADDRESS",font1,'#696969');
    create_light(W*0.05,370,200,40,"SYLLABLE",font1,'#696969');
    
    create_light(W*0.07,100,40,40,"1",font1,'#4d0400');
    create_light(W*0.14,100,40,40,"2",font1,'#4d0400');
    create_light(W*0.21,100,40,40,"3",font1,'#4d0400');
    create_light(W*0.28,100,40,40,"4",font1,'#4d0400');
    create_light(W*0.35,100,40,40,"5",font1,'#4d0400');
    create_light(W*0.42,100,40,40,"6",font1,'#4d0400');
    create_light(W*0.49,100,40,40,"7",font1,'#4d0400');
    create_light(W*0.56,100,40,40,"8",font1,'#4d0400');
    create_light(W*0.63,100,40,40,"9",font1,'#4d0400');
    create_light(W*0.70,100,40,40,"10",font1,'#4d0400');
    create_light(W*0.77,100,40,40,"11",font1,'#4d0400');
    create_light(W*0.84,100,40,40,"12",font1,'#4d0400');
    create_light(W*0.91,100,40,40,"13",font1,'#4d0400');

    create_light(W*0.12,200,40,40,"ERROR RESET",10,'#4d0400');
    create_light(W*0.22,200,40,40,"ERROR PARITY",10,'#4d0400');
    create_light(W*0.32,200,40,40,"MEM BUFFER PARITY",10,'#4d0400');
    create_light(W*0.42,200,40,40,"MEM BUFFER REG",10,'#4d0400');
    create_light(W*0.52,200,40,40,"TRANS REG",10,'#4d0400');

    create_light(W*0.91-126,200,40,40,"OP4",12,'#4d0400');
    create_light(W*0.91-84,200,40,40,"OP3",12,'#4d0400');
    create_light(W*0.91-42,200,40,40,"OP2",12,'#4d0400');
    create_light(W*0.91,200,40,40,"OP1",12,'#4d0400');

    create_light(W*0.91-462,300,40,40,"A9",12,'#4d0400');
    create_light(W*0.91-420,300,40,40,"A8",12,'#4d0400');
    create_light(W*0.91-378,300,40,40,"A7",12,'#4d0400');
    create_light(W*0.91-336,300,40,40,"A6",12,'#4d0400');
    create_light(W*0.91-294,300,40,40,"A5",12,'#4d0400');
    create_light(W*0.91-252,300,40,40,"A4",12,'#4d0400');
    create_light(W*0.91-210,300,40,40,"A3",12,'#4d0400');
    create_light(W*0.91-168,300,40,40,"A2",12,'#4d0400');
    create_light(W*0.91-126,300,40,40,"A1",12,'#4d0400');

    create_light(W*0.91-462,400,40,40,"0",12,'#4d0400');
    create_light(W*0.91-420,400,40,40,"1",12,'#4d0400');

def update_DMM_screen():
        for widget in frame.winfo_children():
            widget.destroy()
        text_box = tk.Label(frame,text='Multimeter Mode',bg='black',fg='white')
        text_box.place(x=0, y=0)
        if multimeterMode == 1:
            text_box = tk.Label(frame,text='Voltage: ',bg='black',fg='white')
            text_box.place(x=0, y=40)
        elif multimeterMode == 2:
            text_box = tk.Label(frame,text='Current: ',bg='black',fg='white')
            text_box.place(x=0, y=40)

def close_window():
    app.destroy()




#Sets up the initial window for the interface
app = tk.Tk()
app.title('LVDC Desktop Programmer')
canvas = tk.Canvas(app, height=H, width=W)
canvas.pack()
frame = tk.Frame(app,bg='#696969')
frame.place(relwidth=1,relheight=1)
place_lights()
#canvas.create_line(0,1200,600,1200, fill="green", width=20)

app.mainloop()

#atexit.register(handle_exit)
