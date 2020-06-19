using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;

using System.Windows.Forms;
using System.Drawing;


namespace usb_esp32_ui
{
    class Command
    {
        SerialPort serialPort;

        public Command(SerialPort sP)
        {
            serialPort = sP;
        }

        /// <summary>
        /// Opens Port if not already open
        /// </summary>
        public void Open()
        {
            if (serialPort.IsOpen == false)
            {
                serialPort.Open();
            }
        }
        public void Open(Control status)
        {
            if (serialPort.IsOpen == false)
            {
                serialPort.Open();
                status.BackColor = Color.LightGreen;
            }
        }


        /// <summary>
        /// Send a command
        /// </summary>
        /// <param name="command"></param>
        /// <param name="args"></param>
        /// <param name="warningNotification"> Messagebox if port is not open </param>
        public void SendCommand(int command, string args, bool warningNotification = true)
        {
            if (serialPort.IsOpen == true)
            {
                string text = command.ToString() + ":" + args;
                serialPort.Write(text);
            }
            else if (warningNotification)
            {
                MessageBox.Show("Port not open");
            }
        }


    }
}
