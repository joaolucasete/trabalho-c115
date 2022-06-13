# 1 "c:\\Users\\joaop\\OneDrive - Instituto Nacional de Telecomunicações\\Inatel\\2022-1-SEMESTRE\\C115-L1\\Atividades\\Projeto-Final\\trabalho-final.ino"
# 2 "c:\\Users\\joaop\\OneDrive - Instituto Nacional de Telecomunicações\\Inatel\\2022-1-SEMESTRE\\C115-L1\\Atividades\\Projeto-Final\\trabalho-final.ino" 2




// Conecte pino 1 do sensor (esquerda) ao +5V
// Conecte pino 2 do sensor ao pino de dados definido em seu Arduino
// Conecte pino 4 do sensor ao GND
// Conecte o resistor de 10K entre pin 2 (dados)
// e ao pino 1 (VCC) do sensor
DHT dht(A1 /* pino que estamos conectado*/, DHT11 /* DHT 11*/);

String command;
float h;
float t;

unsigned long leitura_tempo = millis();

void setup()
{
    Serial.begin(9600);
    pinMode(13, 0x1);
    dht.begin();
}

void loop()
{

    if (Serial.available() > 0)
    {
        command = Serial.readStringUntil('#');

        if (command == "1")
        {
            digitalWrite(13, 0x1);
        }
        else if (command == "0")
        {
            digitalWrite(13, 0x0);
        }
        else if (command == "buzzer_on")
        {
            digitalWrite(8, 0x1);
        }
        else if (command == "buzzer_off")
        {
            digitalWrite(8, 0x0);
        }
    }

    if ((millis() - leitura_tempo) > 1000)
    {
        leitura_tempo = millis();
        le_temp_e_umid();
    }
}

void le_temp_e_umid()
{
    h = dht.readHumidity();
    t = dht.readTemperature();
    Serial.println(String(h) + ";" + String(t));
}
