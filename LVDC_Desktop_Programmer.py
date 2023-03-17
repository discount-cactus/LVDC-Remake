#LVDC Desktop Programmer
#When connected to the input interface, the connected laptop can send instructions to the board

# 1. Opens instruction file
# 2. Compiles instruction file
# 3. Establishes communication to Arduino programmer
# 4. Opens app window

# https://www.freecodecamp.org/news/python-get-current-time/

from datetime import datetime
import tkinter as tk
import tkinter.font as font
import os
import serial
import time

#Establishes the port to link to the ground computer
address = "/dev/cu.usbserial-14310"
port = serial.Serial(address,9600)
port.timeout = 1

H = 900
W = 450
pageMode = 0
multimeterMode = 0

MESSAGE = b'Z'
tempData = [0,0,0,0,0,0,0]
data = [0,0,0,0]
i = 0

#Initializes pages
def create_button(xx,yy,w,h,title,ft,bk,func):
    buttonFont = font.Font(family='Helvetica', size=ft)
    #l= tk.Label(frame,text=title, bg=bk, font = buttonFont)
    #l.place(x=(W*0.05)+xx,y=(W*0.05)+yy,width=w,height=h)
    b = tk.Button(frame, text=title, highlightbackground = bk, command=func, font=buttonFont)
    b.place(x=(W*0.05)+xx,y=(W*0.05)+yy,width=w,height=h)

def global_buttons():
    for widget in frame.winfo_children():
        widget.destroy()
    for widget in frame_screen.winfo_children():
        widget.destroy()
    create_button(20,300,60,40,"F1",16,'#141452',page_F1);
    create_button(120,300,60,40,"F2",16,'#141452',page_F2);
    create_button(220,300,60,40,"F3",16,'#141452',page_F3);
    create_button(320,300,60,40,"F4",16,'#141452',page_F4);
    create_button(20,420,60,40,"PWR",12,'white',close_window);
    create_button(20,480,60,40,"MODE",12,'white',change_mode);

    create_button(184,415,30,30,"UP",8,'white',close_window);
    create_button(184,495,30,30,"DOWN",8,'white',close_window);
    create_button(130,455,30,30,"LEFT",8,'white',close_window);
    create_button(240,455,30,30,"RIGHT",8,'white',close_window);

    multimeterMode = 0

#def handle_exit():
#    print("Closing...")

def page_F4():
    #F4 - Oscilloscope
    global_buttons()
    global pageMode
    global multimeterMode

    text_box = tk.Label(frame_screen,text='Oscilloscope Mode',bg='black',fg='white')
    text_box.place(x=0, y=0)

    fig = Figure(dpi = 100, linewidth=0.1)  # the figure that will contain the plot
    y = [i**2 for i in range(101)]  # list of squares
    plot1 = fig.add_subplot(111,xlabel="X-Axis",ylabel="Y-Axis",title="Title")  # adding the subplot
    plot1.plot(y)
    plot1.grid()
    canvas = FigureCanvasTkAgg(fig,master=frame_screen)    # creating the Tkinter canvas containing the Matplotlib figure
    canvas.draw()
    canvas.get_tk_widget().pack()       #placing the canvas on the Tkinter window
    toolbar = NavigationToolbar2Tk(canvas, frame_screen)
    toolbar.update()
    canvas.get_tk_widget().pack()       #placing the canvas on the Tkinter window

    #TEST GRAPH
    x = np.linspace(0,20,101)
    y = [i**2 for i in range(101)]
    fig = Figure(dpi = 100, linewidth=0.5)
    fig.patch.set_facecolor('#141452')
    plot1 = fig.add_subplot(111,xlabel="X-Axis",ylabel="Y-Axis")
    plot1.set_title('Title', color='white', fontsize=10)
    plot1.patch.set_facecolor('white')
    plot1.plot(x, y, color='red')
    plot1.grid()
    Axes.tick_params(self=plot1, axis='both', labelsize=6, colors='white')
    canvas = FigureCanvasTkAgg(fig,master=frame_screen)
    canvas.draw()
    canvas.get_tk_widget().pack()

    pageMode = 4

def close_window():
    app.destroy()

def change_mode():
    global pageMode
    global multimeterMode

    if pageMode == 2:
        multimeterMode = multimeterMode + 1
        if multimeterMode == 9:
            multimeterMode = 1

def update_DMM_screen():
    global pageMode
    if pageMode == 2:
        global multimeterMode

        for widget in frame_screen.winfo_children():
            widget.destroy()
        text_box = tk.Label(frame_screen,text='Multimeter Mode',bg='black',fg='white')
        text_box.place(x=0, y=0)
        if multimeterMode == 1:
            text_box = tk.Label(frame_screen,text='Voltage: ',bg='black',fg='white')
            text_box.place(x=0, y=40)
        elif multimeterMode == 2:
            text_box = tk.Label(frame_screen,text='Current: ',bg='black',fg='white')
            text_box.place(x=0, y=40)
        elif multimeterMode == 3:
            text_box = tk.Label(frame_screen,text='Power: ',bg='black',fg='white')
            text_box.place(x=0, y=40)
        elif multimeterMode == 4:
            text_box = tk.Label(frame_screen,text='Resistance: ',bg='black',fg='white')
            text_box.place(x=0, y=40)
        elif multimeterMode == 5:
            text_box = tk.Label(frame_screen,text='Capacitance: ',bg='black',fg='white')
            text_box.place(x=0, y=40)
        elif multimeterMode == 6:
            text_box = tk.Label(frame_screen,text='Impedance: ',bg='black',fg='white')
            text_box.place(x=0, y=40)
        elif multimeterMode == 7:
            text_box = tk.Label(frame_screen,text='Continuity: ',bg='black',fg='white')
            text_box.place(x=0, y=40)
        elif multimeterMode == 8:
            text_box = tk.Label(frame_screen,text='Signal: ',bg='black',fg='white')
            text_box.place(x=0, y=40)

        app.after(50,update_DMM_screen)

#Important button function definitions
def InitiateCountdown():
    commFile = open("GCtoLAPTOP.txt","w")
    commFile.truncate(0)
    commFile.write("C")
    commFile.close()
    global MESSAGE
    MESSAGE = b'C'

def Abort():
    commFile = open("GCtoLAPTOP.txt","w")
    commFile.truncate(0)
    commFile.write("D")
    commFile.close()
    global MESSAGE
    MESSAGE = b'D'

#Manual State Change function definitions
def ManualSetState1():
    current_date_and_time = datetime.now()  #Integrate datatime stamp with file name, BOOKMARKED RIGHT NOW
    commFile = open("GCtoLAPTOP.txt","w")
    commFile.truncate(0)
    commFile.write("1")
    commFile.close()
    global MESSAGE
    MESSAGE = b'1'





#Sets up the initial window for the interface
INSTRUCTIONFILE = open("instructionfile.txt","r")

app = tk.Tk()
app.title('LVDC Desktop Programmer')
canvas = tk.Canvas(app, height=H, width=W)
canvas.pack()
frame = tk.Frame(app,bg='#141452')
frame.place(relwidth=1,relheight=1)
frame_screen = tk.Frame(app,bg='black')
frame_screen.place(x=W*0.05, y=W*0.05, relwidth=0.9,relheight=0.35)

page_F1()
app.after(5,serialWR)
app.mainloop()

#atexit.register(handle_exit)
