namespace usb_esp32_ui
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.open_serial_btn = new System.Windows.Forms.Button();
            this.display_write_textbox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.display_write_btn = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.status_img = new System.Windows.Forms.TextBox();
            this.status_led_btn = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.status_led_textbox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // open_serial_btn
            // 
            this.open_serial_btn.Location = new System.Drawing.Point(500, 272);
            this.open_serial_btn.Name = "open_serial_btn";
            this.open_serial_btn.Size = new System.Drawing.Size(160, 31);
            this.open_serial_btn.TabIndex = 0;
            this.open_serial_btn.Text = "Open Serial Port";
            this.open_serial_btn.UseVisualStyleBackColor = true;
            this.open_serial_btn.Click += new System.EventHandler(this.open_serial_btn_Click);
            // 
            // display_write_textbox
            // 
            this.display_write_textbox.Location = new System.Drawing.Point(105, 114);
            this.display_write_textbox.Name = "display_write_textbox";
            this.display_write_textbox.Size = new System.Drawing.Size(338, 20);
            this.display_write_textbox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(58, 117);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Display";
            // 
            // display_write_btn
            // 
            this.display_write_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.display_write_btn.Location = new System.Drawing.Point(449, 114);
            this.display_write_btn.Name = "display_write_btn";
            this.display_write_btn.Size = new System.Drawing.Size(124, 20);
            this.display_write_btn.TabIndex = 3;
            this.display_write_btn.Text = "Write";
            this.display_write_btn.UseVisualStyleBackColor = true;
            this.display_write_btn.Click += new System.EventHandler(this.display_write_btn_Click);
            // 
            // serialPort1
            // 
            this.serialPort1.BaudRate = 115200;
            this.serialPort1.PortName = "COM4";
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(449, 38);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(124, 21);
            this.comboBox1.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(62, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Status";
            // 
            // status_img
            // 
            this.status_img.BackColor = System.Drawing.Color.Black;
            this.status_img.Location = new System.Drawing.Point(105, 38);
            this.status_img.Name = "status_img";
            this.status_img.ReadOnly = true;
            this.status_img.Size = new System.Drawing.Size(79, 20);
            this.status_img.TabIndex = 6;
            this.status_img.Text = "Port status";
            // 
            // status_led_btn
            // 
            this.status_led_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.status_led_btn.Location = new System.Drawing.Point(449, 140);
            this.status_led_btn.Name = "status_led_btn";
            this.status_led_btn.Size = new System.Drawing.Size(124, 20);
            this.status_led_btn.TabIndex = 9;
            this.status_led_btn.Text = "Change LED";
            this.status_led_btn.UseVisualStyleBackColor = true;
            this.status_led_btn.Click += new System.EventHandler(this.status_led_btn_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(38, 144);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(61, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "LED Status";
            // 
            // status_led_textbox
            // 
            this.status_led_textbox.Location = new System.Drawing.Point(105, 140);
            this.status_led_textbox.Name = "status_led_textbox";
            this.status_led_textbox.Size = new System.Drawing.Size(338, 20);
            this.status_led_textbox.TabIndex = 7;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(672, 315);
            this.Controls.Add(this.status_led_btn);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.status_led_textbox);
            this.Controls.Add(this.status_img);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.display_write_btn);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.display_write_textbox);
            this.Controls.Add(this.open_serial_btn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button open_serial_btn;
        private System.Windows.Forms.TextBox display_write_textbox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button display_write_btn;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox status_img;
        private System.Windows.Forms.Button status_led_btn;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox status_led_textbox;
    }
}

