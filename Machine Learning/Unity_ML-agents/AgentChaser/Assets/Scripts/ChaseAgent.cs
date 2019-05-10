using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using MLAgents;

public class ChaseAgent : Agent
{

    public Rigidbody rb;
    private float xDir;
    private float zDir;

    [SerializeField]
    private Text text;
    private int solved;

    public Transform target;
    public Transform agent;

    public float distance;

    public GUIStyle style;

    public override void CollectObservations()
    {
        Vector3 velocity = agent.GetComponent<Rigidbody>().velocity;
        AddVectorObs(velocity.x);
        AddVectorObs(velocity.z);

        AddVectorObs(Vector3.Distance(agent.transform.position, target.transform.position));
        AddVectorObs(agent.transform.position.x);
        AddVectorObs(agent.transform.position.z);
        AddVectorObs(target.transform.position.x);
        AddVectorObs(target.transform.position.z);
        AddVectorObs(agent.transform.position.x - target.transform.position.x);
        AddVectorObs(agent.transform.position.z - target.transform.position.z);
       
    }

    public override void InitializeAgent()
    {
        style.fontSize = 20;
        style.normal.textColor = Color.red;
    }

    public override void AgentAction(float[] vectorAction, string textAction)
    {

        if(brain.brainParameters.vectorActionSpaceType == SpaceType.continuous)
        {
            xDir = Mathf.Clamp(vectorAction[0], -1f, 1f);
            zDir = Mathf.Clamp(vectorAction[1], -1f, 1f);



        }
        else
        {
            int movement = Mathf.FloorToInt(vectorAction[0]);
            if(movement == 0) { xDir = 0; zDir = 0; }
            if (movement == 1) { xDir = -1; }
            if (movement == 2) { xDir = 1; }
            if (movement == 3) { zDir = -1; }
            if (movement == 4) { zDir = 1; }
        }

        agent.GetComponent<Rigidbody>().AddForce(new Vector3(xDir, 0, zDir), ForceMode.VelocityChange);

        distance = Vector3.Distance(agent.transform.position, target.transform.position);

        if(distance > 100f)
        {
            Done();
            SetReward(-1f);
            return;
        }
        if(distance < 3f)
        {
            solved++;
            Done();
            SetReward(1f);
            return;
        }
        if(text != null)
        {
            text.text = string.Format("S: {0}", solved);
        }



    }

    public override void AgentReset()
    {

        agent.transform.position = new Vector3(0, 0.5f, 0);
        agent.GetComponent<Rigidbody>().velocity = Vector3.zero;
        agent.GetComponent<Rigidbody>().angularVelocity = Vector3.zero;
        target.transform.position = new Vector3(Random.Range(-10, 10), 0.5f, Random.Range(-10, 10));


    }

    public void OnGUI()
    {
        GUI.Label(new Rect(10, 10, 100, 20), "XDirection: "+ xDir, style);
        GUI.Label(new Rect(10, 30, 100, 20), "zDirection: " + zDir, style);
        GUI.Label(new Rect(10, 50, 100, 20), "Cumulative reward: " + GetCumulativeReward(), style);
    }

}
