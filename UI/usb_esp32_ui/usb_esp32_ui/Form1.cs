using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.IO.Ports;

namespace usb_esp32_ui
{
    public partial class Form1 : Form
    {
        Command command;

        public Form1()
        {
            InitializeComponent();
            command = new Command(serialPort1);

        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void open_serial_btn_Click(object sender, EventArgs e)
        {
            command.Open(status_img);
        }

        private void status_led_btn_Click(object sender, EventArgs e)
        {
            command.SendCommand(2, status_led_textbox.Text);
            status_led_textbox.Text = "";
        }

        private void display_write_btn_Click(object sender, EventArgs e)
        {
            command.SendCommand(30, display_write_textbox.Text);
        }

    }
}
