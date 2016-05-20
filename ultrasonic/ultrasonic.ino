    #define CMD_READ_ARDUDROID 13
    #define START_CMD_CHAR '*'
    #define trigPin1 3
    #define echoPin1 2
    #define trigPin2 4
    #define echoPin2 5
    #define trigPin3 7
    #define echoPin3 8

    long duration, distance, RightSensor,FrontSensor,LeftSensor;
    String l,r,f,data;
    void setup()
    {
    Serial.begin(38400);
    Serial.println("Walking stick for blind!");
    Serial.flush();
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
    pinMode(trigPin3, OUTPUT);
    pinMode(echoPin3, INPUT);
    }

    void loop() {
      
  Serial.flush();
        int ard_command = 0;
        int pin_num = 0;
        int pin_value = 0;

        char get_char = ' ';  //read serial

  // wait for incoming data
        if (Serial.available() < 1) return; // if serial empty, return to loop().

  // parse incoming command start flag 
        get_char = Serial.read();
        if (get_char != START_CMD_CHAR) return; //it is * , if no command start flag, return to loop().

  // parse incoming command type
        ard_command = Serial.parseInt();
        if (ard_command != CMD_READ_ARDUDROID)//{ //if it is not 13
          return;
    // char send_to_android[] = "Place your text here." ;
    // Serial.println(send_to_android);   // Example: Sending text
    //Serial.print(" Analog 0 = "); 
    //Serial.println(analogRead(A0));  // Example: Read and send Analog pin value to Arduino
    //return;  // Done. return to loop();
  //}
  while(1){

    delay(1500);
    SonarSensor(trigPin1, echoPin1);
    RightSensor = distance;
    SonarSensor(trigPin2, echoPin2);
    LeftSensor = distance;
    SonarSensor(trigPin3, echoPin3);
    FrontSensor = distance;
    l=String(LeftSensor);
    r=String(RightSensor);
    f=String(FrontSensor);
    data = l + "&" + r + "&" + f;
//    if(RightSensor > 100 && LeftSensor > 100 && FrontSensor > 100){
//      Serial.println("Walk Freely");
//    }
    Serial.println(data);
    //Serial.println( LeftSensor );
    //Serial.println( FrontSensor );
    //Serial.println( RightSensor );
    /*if(RightSensor <= 100 && LeftSensor > 100 && FrontSensor > 100)
    {
            //move left or front
            Serial.println(" object at right");
    }
    
    else if(RightSensor > 100 && LeftSensor <= 100 && FrontSensor > 100)
    {
            //move right or front
            Serial.println(" object at left");
    }
    
    else if(RightSensor > 100 && LeftSensor > 100 && FrontSensor <= 100)
    {
            //move right or left
            Serial.println(" object at front");
    }
     
    else if(RightSensor <= 100 && LeftSensor <= 100 && FrontSensor > 100)
    {
            //move front
            Serial.println(" object at left and right !");
            delay(300);
    }
    
    else if(RightSensor <= 100 && LeftSensor > 100 && FrontSensor <= 100)
    {
            //move left
            Serial.println(" object at front and right !");
            delay(300);
    }
    
    else if(RightSensor > 100 && LeftSensor <= 100 && FrontSensor <= 100)
    {
            //move right
            Serial.println(" object at left and front !");
            delay(300);
    }
    
    else if(RightSensor <= 100 && LeftSensor <= 100 && FrontSensor <= 100)
    {
            //move back
            Serial.println(" Please go Back !");
    }*/
     /* Serial.print(LeftSensor);
      Serial.print(" , ");
      Serial.print(FrontSensor);
      Serial.print(" , ");
      Serial.println(RightSensor);*/
    }
    }
    void SonarSensor(int trigPin,int echoPin)
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration/2) / 29.1;
    }
