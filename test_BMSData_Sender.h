

float ReadDataFromSensor(float parameter_Maximum, float parameter_Minimum)
{
  srand(time(0));
  float data = (rand() % (int)(parameter_Maximum+1)) ;
  if(data < parameter_Minimum)
  {
    data = data + parameter_Minimum;
  }
  return data;
}


float (*funp_ReadDataFromSensor)(float,float) = ReadDataFromSensor;
